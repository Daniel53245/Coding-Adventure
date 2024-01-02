int tribonacci(int n){
        switch (n){
                case 0:
                        return 0;
                case 1:
                        return 1;
                case 2:
                        return 1;
        }
        int list[n+1];
        list[0] = 0;
        list[1] = 1;
        list[2] = 1;
        for(int i =3;i<n+1;i++){
            list[i] = list[i-1] + list[i-2] + list[i-3];
        }
        return list[n];
}