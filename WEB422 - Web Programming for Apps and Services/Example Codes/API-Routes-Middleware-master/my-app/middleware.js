import { NextResponse } from 'next/server';

export function middleware(request) {

  if (request.nextUrl.pathname.startsWith('/about')) {
    const requestHeaders = new Headers(request.headers);
    const language = requestHeaders.get('Accept-Language');

    if (language.includes('fr')) {
      return NextResponse.rewrite(new URL('/fr/about', request.url));
    }
  }

  const response = NextResponse.next();

  if (request.nextUrl.pathname.startsWith('/setCookie')) {
    let cookieMessage = request.nextUrl.searchParams.get('message');
    response.cookies.set('message', cookieMessage);
  }

  if (request.nextUrl.pathname.startsWith('/getCookie')) {
    let cookie = request.cookies.get('message');
    console.log(cookie);
  }

  return response;
  
}