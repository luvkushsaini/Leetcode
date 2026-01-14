class H2O {

    private Semaphore hydrogenSema;
    private Semaphore oxygenSema;
    private Semaphore barrier;

    public H2O() {
        hydrogenSema=new Semaphore(2);
        oxygenSema =new Semaphore(1);
        barrier=new Semaphore(0);

    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		
        hydrogenSema.acquire();
        releaseHydrogen.run();

        barrier.release();

    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {

        oxygenSema.acquire();
        releaseOxygen.run();

        barrier.acquire(2);

        oxygenSema.release(1);
        hydrogenSema.release(2);


        
		
    }
}