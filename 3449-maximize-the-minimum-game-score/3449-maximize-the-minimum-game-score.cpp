class Solution {
public:

    int n;

    bool fun(vector<int>& points, int m, long long mid){

        long long count = 0;
        long long prev = 0;

        int i = 0;

        while(i < n - 1){

            count++;

            if(count > m) return false;

            long long val;

            if(prev > mid / points[i]){
                val = mid + 1;
            }
            else{
                val = prev * 1LL * points[i];
            }

            long long num = mid - (points[i] + val);

            if(num <= 0){
                prev = 0;
                i++;
                continue;
            }

            long long div =
                (num + points[i] - 1) / points[i];

            if(div > (LLONG_MAX - count) / 2){
                return false;
            }

            count += 2LL * div;

            if(count > m) return false;

            prev = div;

            i++;
        }

        long long val;

        if(prev > mid / points[n - 1]){
            val = mid + 1;
        }
        else{
            val = prev * 1LL * points[n - 1];
        }

        long long num = mid - val;

        if(num > 0){

            long long div =
                (num + points[n - 1] - 1)
                / points[n - 1];

            count++;

            if(count > m) return false;

            if(div > 0){

                div--;

                if(div > (LLONG_MAX - count) / 2){
                    return false;
                }

                count += 2LL * div;
            }
        }

        return count <= 1LL * m;
    }

    long long maxScore(vector<int>& points, int m) {

        n = points.size();

        long long low =
            *min_element(points.begin(), points.end());

        long long mx =
            *max_element(points.begin(), points.end());

        long long high = 1LL * mx * m;

        long long ans = 0;

        while(low <= high){

            long long mid =
                low + (high - low) / 2;

            if(fun(points, m, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};