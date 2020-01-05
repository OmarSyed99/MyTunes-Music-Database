/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                   */
/*  Program:  MyTunes Music Player                   */
/*  Author:   (c) 2019 Louis Nel                     */
/*  All rights reserved.  Distribution and           */
/*  reposting, in part or in whole, requires         */
/*  written consent of the author.                   */
/*                                                   */
/*  COMP 2404 students may reuse this content for    */
/*  their course assignments without seeking consent */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _SONGS_H
#define _SONGS_H

#include <ostream>
#include <vector>
#include <string>
using namespace std;
#include "UI.h"
#include "song.h"

class Songs {
	/*
	Songs represents a collection of compositions, specifically Song objects
	A Songs container OWNS the songs within it.
	If the container is destroyed it deletes the Song objects it contains
	If a song is removed from the container the Song object is deleted from heap space.
	*/
	public:
	Songs();
	~Songs(void);
	Song * findByID(int anID);
	void add(Song & aSong);
	void remove(Song & aSong);
	void showOn(UI & aView);
	void showOn(UI & aView, int memberID);
	private:
	vector<Song*> collection;
	vector<Song*>::iterator findPosition(Song & aSong);
};

#endif
