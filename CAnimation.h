//==============================================================================
// Animation Class
//==============================================================================
#ifndef _CANIMATION_H_
    #define _CANIMATION_H_

#include <SDL/SDL.h>

//==============================================================================
class CAnimation {
	private:
		int	    CurrentFrame;

		int     FrameInc;

		int     AnimationFrames[40];

    private:
        int     FrameRate; //Milliseconds

		long    OldTime;

	public:
        int	    MaxFrames;

		bool	Oscillate;

		int GetAnimationFrames(int Animation);

		void SetAnimationFrames(int Animation, int NFrames);

	public:
		CAnimation();

		void OnAnimate(int D);

	public:
        void SetFrameRate(int Rate);

		void SetCurrentFrame(int Frame);

		int GetCurrentFrame();
};

//==============================================================================

#endif
