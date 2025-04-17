describe('login / logout flow specification', () => {

  it('cannot navigate to /profile-sg without being logged in', () => {
    cy.visit("/profile-sg")
    .url().should('include', "/login");
  });

  it('rejects a login attempt by an invalid github user: !!!', () => {
    cy.visit("/login")
    .get('input[name="username"]').type("!!!").type("{enter}")
    .url().should('include', "/login");
  });

  it('successfully authenticates a valid github user: test-account and logs out', () => {
    cy.visit("/login")
    .get('input[name="username"]').type("test-account").type("{enter}")
    .url().should('include', '/profile-sg')
    .get("nav").contains("Logout").click()
    .url().should('include', "/login");
  });

});