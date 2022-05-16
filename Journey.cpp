#include "Journey.h"


Journey::Journey(String destination, Date start, Date end, int grade, String comment, String photos)
{
	setDestination(destination);
	setStart(start);
	setEnd(end);
	setGrage(grade);
	setComment(comment);
	setPhotos(photos);
}
void Journey::setDestination(String dest)
{
	destination = dest;
}
void Journey::setStart(Date date)
{
	start = date;
}
void Journey::setEnd(Date date)
{
	end = date;
}
void Journey::setGrage(int rate)
{
	grade = rate;
}
void Journey::setComment(String text)
{
	comment = text;
}
void Journey::setPhotos(String list)
{
	photos = list;

}

String Journey::getDestination() const
{
	return destination;
}

String Journey::getComment() const
{
	return comment;
}

String Journey::getPhotos() const
{
		return photos;
}

Date Journey::getStart() const
{
	return start;
}

Date Journey::getEnd() const
{
	return end;
}

int Journey::getGrade() const
{
	return grade;
}

std::ostream& operator<<(std::ostream& out, const Journey& trip)
{
	return out << trip.destination << ' ' << trip.start << ' ' << trip.end << ' ' << trip.grade << ' ' << trip.comment << ' '<<trip.photos;
}
