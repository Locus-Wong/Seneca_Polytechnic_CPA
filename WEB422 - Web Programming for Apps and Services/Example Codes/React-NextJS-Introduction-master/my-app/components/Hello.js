export default function Hello({
    fName = 'First Name',
    lName = 'Last Name',
  }) {
    return (
      <p>
        Hello {fName} {lName}!
      </p>
    );
  }