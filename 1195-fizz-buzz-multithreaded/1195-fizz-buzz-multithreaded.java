class FizzBuzz {
    private int n;
    private Semaphore[] semaphore;

    public FizzBuzz(int n) {
        this.n = n;
        semaphore=new Semaphore[4];
       for(int i=0;i<4;i++){
        if(i==0)semaphore[i]=new Semaphore(1);
        else semaphore[i]=new Semaphore(0);
       }

    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for(int  i=1;i<=n;i++){
            if(i%3==0 && i%5!=0){
         semaphore[1].acquire();
         printFizz.run();

         semaphore[0].release();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for(int i=1;i<=n;i++){
            if(i%5==0 && i%3!=0){
        semaphore[2].acquire();

        printBuzz.run();

        semaphore[0].release();
            }
        }
        
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for(int i=1;i<=n;i++){
        if(i%3==0 && i%5==0){
        semaphore[3].acquire();
        printFizzBuzz.run();

        semaphore[0].release();
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for(int i=1;i<=n;i++){
             semaphore[0].acquire();

            if(i%3!=0 && i%5!=0){
                printNumber.accept(i) ;
                semaphore[0].release();
            }
            else if(i%3==0 && i%5!=0){
                semaphore[1].release();
            }
            else if(i%3!=0 && i%5==0){
                semaphore[2].release();
            }
            else{
                semaphore[3].release();
            }
        }

    }
}