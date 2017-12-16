#ifndef _RENDERER_H
#define _RENDERER_H

/*
	Renders the game
*/
class Renderer
{
public:
	Renderer();
	~Renderer();

	virtual void draw() = 0; 

private:

protected:

};

#endif