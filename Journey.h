#pragma once
#include <iostream>
#include"String.h"
#include"DynamicArray.h"
#include"Dates.h"

class Journey
{
	String destination;
	Date start;
	Date end;
	int grade;
	String comment;
	String photos;
public:
	Journey() = default;
	Journey(String destination, Date start, Date end, int grade, String comment, String photos);

	String getDestination() const;
	String getComment() const;
    String getPhotos() const;
	Date getStart() const;
	Date getEnd() const;
	int getGrade() const;

	void setDestination(String dest);
	void setStart(Date date);
	void setEnd(Date date);
	void setGrage(int rate);
	void setComment(String text);
	void setPhotos(String list);

	friend std::ostream& operator<<(std::ostream& out, const Journey& trip);
};