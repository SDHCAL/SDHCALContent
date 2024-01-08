#ifndef SDHCAL_DBSCAN_H
#define SDHCAL_DBSCAN_H

// this an example to use mlpack and dlib
// For dlib, we have to define __COMPILE_DLIB__ from cmake configuration.

namespace sdhcal_content
{

class SDHCALDBSCAN
{
public:

	SDHCALDBSCAN();

#if __COMPILE_DLIB__
	void DoClustering();
	void DoGraph();
#endif

private:

};

}

#endif
