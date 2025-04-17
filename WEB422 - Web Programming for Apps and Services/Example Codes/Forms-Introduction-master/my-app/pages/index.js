
import FormWithValidation from '@/components/FormWithValidation'
import SimpleForm from '@/components/SimpleForm'
import UserForm from '@/components/UserForm'

export default function Home() {
  return (
    <>
      <h3>&ldquo;Simple&rdquo; Form using a Controlled Component</h3>
      <hr /><br />
      <SimpleForm />
      <br /><br />
      <h3>&ldquo;User&rdquo; Form using React Hook Form</h3>
      <hr /><br />
      <UserForm />
      <br /><br />
      <h3>Form with Validation</h3>
      <hr /><br />
      <FormWithValidation />
    </>
  )
}
