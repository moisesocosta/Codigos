/// <reference types="Cypress"/>

describe('Testes Funcional de Login', () => {
  it('Deve realizar o login com sucesso', () => {
    cy.login_teste('standard_user','secret_sauce')
    cy.get('.title').should('contain', 'Products')
  });

  it('Validando Login Incorreto', () => {
    cy.login_teste('incorreto','secret_sauce')
    cy.get('[data-test="error"]').should('contain', 'Epic sadface: Username and password do not match any user in this service')
  });

  it('Validando Senha Incorreta', () => {
    cy.login_teste('standard_user','incorreta')
    cy.get('[data-test="error"]').should('contain', 'Epic sadface: Username and password do not match any user in this service')
  });
})