const main_thread = (argc) => {
    console.log('global' , argc);
    console.log('arrow' , this);
    let i=0;
    for(;i<3;i++){
        console.log(i);
        setTimeout(() => console.log('cb: ' , i , this , argc) , 0);
    }
}

main_thread(this);
