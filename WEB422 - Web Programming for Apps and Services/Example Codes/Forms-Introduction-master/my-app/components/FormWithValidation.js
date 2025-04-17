import { useForm } from 'react-hook-form';
import { useEffect } from 'react';

export default function FormWithValidation() {

    const { register, handleSubmit, setValue, formState: { errors } } = useForm({
        defaultValues: {
            firstName: "",
            lastName: "",
            age: 0
        }
    });

    useEffect(() => {
        let data = {
            firstName: "Homer",
            lastName: "Simpson",
            age: 41
        }

        // set the values of each form field to match "data"
        for (const prop in data) {
            setValue(prop, data[prop]);
        }
    }, [setValue]);

    function submitForm(data) {
        console.log(data);
    }

    return (
        <form onSubmit={handleSubmit(submitForm)}>
            First Name: <br />
            <input className={errors.firstName && "inputError"} {...register("firstName", { required: true, maxLength: 20 })} />
            {errors.firstName?.type === "required" && <span className="inputErrorText"><br />First Name is required</span>}
            {errors.firstName?.type === "maxLength" && <span className="inputErrorText"><br />First Name Cannot contain more than 20 characters</span>}<br /><br />

            <input className={errors?.lastName && "inputError"} {...register("lastName", { pattern: /^[A-Za-z]+$/i })} />
            {errors.lastName?.type === "pattern" && <span className="inputErrorText"><br />Last Name must only contain letters</span>}<br /><br />

            <input className={errors?.age && "inputError"} type="number" {...register("age", { min: 18, max: 99 })} />
            {errors.age?.type === "min" && <span className="inputErrorText"><br />Age must be greater than 17 </span>}
            {errors.age?.type === "max" && <span className="inputErrorText"><br />age must be less than 100</span>}<br /><br />

            <button type="submit" disabled={Object.keys(errors).length > 0}>Update User</button>
        </form>
    );
}