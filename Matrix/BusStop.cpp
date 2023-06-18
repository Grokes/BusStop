#include "BusStop.h"

template<typename T>
double SrArifm(const std::vector<T>& arr)
{
	double result{};
	for (int i{}; i < arr.size(); ++i)
		result += arr[i];
	return result / arr.size();
}

void BusStop::Start()
{
	if (end)
	{
		std::cout << "Конечная остановка, пассажиры не садятся";
		return;
	}

	size_t empty_seats{};
	size_t empty_seats_max{ 16 };
	std::vector<size_t> waiting_time_people;
	std::vector<double> waiting_time_sr;
	const size_t min_works = 60 * 4;
	bool override{};

	for (size_t minutes{}; minutes < min_works; ++minutes)
	{
		if (minutes % people_time == 0)
		{
			people_queue.Add(people_time);
			if (people_queue.IsFull())
				override = true;
		}

		if (minutes % bus_time == 0 && minutes != 0)
		{
			empty_seats = rand() % (empty_seats_max + 1);
			if (!empty_seats)
				continue;
			waiting_time_people.clear();
			
			for (size_t i{}; i < empty_seats && !people_queue.IsEmpty(); ++i)
			{
				waiting_time_people.push_back(people_queue.GetCount() * people_time);
				people_queue.Extract();
			}
			if(!waiting_time_people.empty())
				waiting_time_sr.push_back(SrArifm(waiting_time_people));
		}
	}

	std::cout << "Статистика:" << std::endl;
	std::cout << "Среднее время ожидания : " << SrArifm(waiting_time_sr) << std::endl;
	if (override)
	{
		std::cout << "остановка была перегружена\n";
		std::cout << "Оптимальный интервал прихода автобусов (перегруз в 1/3 случаев за смену): ";
		int sr_ostatok = (bus_time / people_time) - (empty_seats_max / 3);
		while (sr_ostatok * (int)(min_works / bus_time) + (int)(bus_time / people_time) > (int)capacity)
		{
			--bus_time;
			sr_ostatok = (bus_time / people_time) - (empty_seats_max / 3);
		}
		std::cout << bus_time << " минут";
	}
	else
	{
		std::cout << "остановка не была перегружена\n";
		std::cout << "Оптимальный интервал прихода автобусов (перегруз в 1/3 случаев за смену): ";
		int sr_ostatok = (bus_time / people_time) - (empty_seats_max / 3);
		while (sr_ostatok * (int)(min_works / bus_time) + (int)(bus_time / people_time) < (int)capacity)
		{
			++bus_time;
			sr_ostatok = (bus_time / people_time) - (empty_seats_max / 3);
		}
		std::cout << --bus_time << " минут";
	}
}

// Когда я начинал это писать, только Бог и я понимали, что я делаю
// Сейчас остался только Бог
