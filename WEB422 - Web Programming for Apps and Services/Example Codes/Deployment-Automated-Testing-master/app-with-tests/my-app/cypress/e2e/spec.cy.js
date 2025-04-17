
describe('check Not Found (404)', ()=>{
  it('should return status 404 when visiting /unknown', ()=>{
    // See Request: https://docs.cypress.io/api/commands/request and 
    // Its: https://docs.cypress.io/api/commands/its for more information regarding this test
    cy.request({url: '/unknown', failOnStatusCode: false}).its('status').should('equal', 404)
  })
});
