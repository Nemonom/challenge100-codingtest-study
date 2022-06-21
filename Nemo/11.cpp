int maxArea(vector<int>& height) {
        	int left = 0, right = height.size() - 1, maxSize = 0;

	while (left < right)
	{
    int h = min(height[left], height[right]);        
		maxSize = max(maxSize, h * (right - left));

		if (height[left] <= height[right])
			left++;
	  else
			right--;
	}
	return maxSize;
}
