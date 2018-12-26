
#include "Robot_statechart.h"
#include <string.h>

/*! \file Implementation of the state machine 'robot_statechart'
*/



Robot_statechart::Robot_statechart():
	stateConfVectorPosition(0),
	ifaceCtrl()
{
}

Robot_statechart::~Robot_statechart()
{
}


void Robot_statechart::init()
{
	for (sc_ushort i = 0; i < maxOrthogonalStates; ++i)
		stateConfVector[i] = Robot_statechart_last_state;
	
	stateConfVectorPosition = 0;

	clearInEvents();
	clearOutEvents();
	
}

void Robot_statechart::enter()
{
	/* Default enter sequence for statechart robot_statechart */
	enseq_main_region_default();
}

void Robot_statechart::exit()
{
	/* Default exit sequence for statechart robot_statechart */
	exseq_main_region();
}

sc_boolean Robot_statechart::isActive() const
{
	return stateConfVector[0] != Robot_statechart_last_state;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean Robot_statechart::isFinal() const
{
   return false;}

void Robot_statechart::runCycle()
{
	
	clearOutEvents();
	for (stateConfVectorPosition = 0;
		stateConfVectorPosition < maxOrthogonalStates;
		stateConfVectorPosition++)
		{
			
		switch (stateConfVector[stateConfVectorPosition])
		{
		case main_region_not_driving_r1_stopped :
		{
			main_region_not_driving_r1_stopped_react(true);
			break;
		}
		case main_region_not_driving_r1_rotating :
		{
			main_region_not_driving_r1_rotating_react(true);
			break;
		}
		case main_region_driving_r1_driving_forwads :
		{
			main_region_driving_r1_driving_forwads_react(true);
			break;
		}
		case main_region_driving_r1_driving_backwards :
		{
			main_region_driving_r1_driving_backwards_react(true);
			break;
		}
		default:
			break;
		}
	}
	clearInEvents();
}

void Robot_statechart::clearInEvents()
{
	ifaceCtrl.userEvent_raised = false;
}

void Robot_statechart::clearOutEvents()
{
}


sc_boolean Robot_statechart::isStateActive(Robot_statechartStates state) const
{
	switch (state)
	{
		case main_region_not_driving : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_NOT_DRIVING] >= main_region_not_driving
				&& stateConfVector[SCVI_MAIN_REGION_NOT_DRIVING] <= main_region_not_driving_r1_rotating);
		case main_region_not_driving_r1_stopped : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_NOT_DRIVING_R1_STOPPED] == main_region_not_driving_r1_stopped
			);
		case main_region_not_driving_r1_rotating : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_NOT_DRIVING_R1_ROTATING] == main_region_not_driving_r1_rotating
			);
		case main_region_driving : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_DRIVING] >= main_region_driving
				&& stateConfVector[SCVI_MAIN_REGION_DRIVING] <= main_region_driving_r1_driving_backwards);
		case main_region_driving_r1_driving_forwads : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_DRIVING_R1_DRIVING_FORWADS] == main_region_driving_r1_driving_forwads
			);
		case main_region_driving_r1_driving_backwards : 
			return (sc_boolean) (stateConfVector[SCVI_MAIN_REGION_DRIVING_R1_DRIVING_BACKWARDS] == main_region_driving_r1_driving_backwards
			);
		default: return false;
	}
}

Robot_statechart::SCI_Ctrl* Robot_statechart::getSCI_Ctrl()
{
	return &ifaceCtrl;
}
/* Functions for event userEvent in interface SCI_Ctrl */
void Robot_statechart::SCI_Ctrl::raise_userEvent(Command value)
{
	userEvent_value = value;
	userEvent_raised = true;
}
Logger Robot_statechart::SCI_Ctrl::get_logger() const
{
	return logger;
}

void Robot_statechart::SCI_Ctrl::set_logger(Logger value)
{
	logger = value;
}

ControlUnit * Robot_statechart::SCI_Ctrl::get_ctrlUnit() const
{
	return ctrlUnit;
}

void Robot_statechart::SCI_Ctrl::set_ctrlUnit(ControlUnit * value)
{
	ctrlUnit = value;
}

CleaningRobot Robot_statechart::SCI_Ctrl::get_robotCtrl() const
{
	return robotCtrl;
}

void Robot_statechart::SCI_Ctrl::set_robotCtrl(CleaningRobot value)
{
	robotCtrl = value;
}


// implementations of all internal functions

/* Entry action for state 'stopped'. */
void Robot_statechart::enact_main_region_not_driving_r1_stopped()
{
	/* Entry action for state 'stopped'. */
	ifaceCtrl.logger.log((sc_string) "Stopped State Entered");
}

/* Entry action for state 'rotating'. */
void Robot_statechart::enact_main_region_not_driving_r1_rotating()
{
	/* Entry action for state 'rotating'. */
	ifaceCtrl.logger.log((sc_string) "Rotating State Entered");
}

/* Entry action for state 'driving_forwads'. */
void Robot_statechart::enact_main_region_driving_r1_driving_forwads()
{
	/* Entry action for state 'driving_forwads'. */
	ifaceCtrl.logger.log((sc_string) "Driving Forwards State Entered");
}

/* Entry action for state 'driving_backwards'. */
void Robot_statechart::enact_main_region_driving_r1_driving_backwards()
{
	/* Entry action for state 'driving_backwards'. */
	ifaceCtrl.logger.log((sc_string) "Driving Backwards State Entered");
}

/* 'default' enter sequence for state not_driving */
void Robot_statechart::enseq_main_region_not_driving_default()
{
	/* 'default' enter sequence for state not_driving */
	enseq_main_region_not_driving_r1_default();
}

/* 'default' enter sequence for state stopped */
void Robot_statechart::enseq_main_region_not_driving_r1_stopped_default()
{
	/* 'default' enter sequence for state stopped */
	enact_main_region_not_driving_r1_stopped();
	stateConfVector[0] = main_region_not_driving_r1_stopped;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state rotating */
void Robot_statechart::enseq_main_region_not_driving_r1_rotating_default()
{
	/* 'default' enter sequence for state rotating */
	enact_main_region_not_driving_r1_rotating();
	stateConfVector[0] = main_region_not_driving_r1_rotating;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state driving_forwads */
void Robot_statechart::enseq_main_region_driving_r1_driving_forwads_default()
{
	/* 'default' enter sequence for state driving_forwads */
	enact_main_region_driving_r1_driving_forwads();
	stateConfVector[0] = main_region_driving_r1_driving_forwads;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state driving_backwards */
void Robot_statechart::enseq_main_region_driving_r1_driving_backwards_default()
{
	/* 'default' enter sequence for state driving_backwards */
	enact_main_region_driving_r1_driving_backwards();
	stateConfVector[0] = main_region_driving_r1_driving_backwards;
	stateConfVectorPosition = 0;
}

/* 'default' enter sequence for region main region */
void Robot_statechart::enseq_main_region_default()
{
	/* 'default' enter sequence for region main region */
	react_main_region__entry_Default();
}

/* 'default' enter sequence for region r1 */
void Robot_statechart::enseq_main_region_not_driving_r1_default()
{
	/* 'default' enter sequence for region r1 */
	react_main_region_not_driving_r1__entry_Default();
}

/* Default exit sequence for state not_driving */
void Robot_statechart::exseq_main_region_not_driving()
{
	/* Default exit sequence for state not_driving */
	exseq_main_region_not_driving_r1();
}

/* Default exit sequence for state stopped */
void Robot_statechart::exseq_main_region_not_driving_r1_stopped()
{
	/* Default exit sequence for state stopped */
	stateConfVector[0] = Robot_statechart_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state rotating */
void Robot_statechart::exseq_main_region_not_driving_r1_rotating()
{
	/* Default exit sequence for state rotating */
	stateConfVector[0] = Robot_statechart_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state driving */
void Robot_statechart::exseq_main_region_driving()
{
	/* Default exit sequence for state driving */
	exseq_main_region_driving_r1();
}

/* Default exit sequence for state driving_forwads */
void Robot_statechart::exseq_main_region_driving_r1_driving_forwads()
{
	/* Default exit sequence for state driving_forwads */
	stateConfVector[0] = Robot_statechart_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for state driving_backwards */
void Robot_statechart::exseq_main_region_driving_r1_driving_backwards()
{
	/* Default exit sequence for state driving_backwards */
	stateConfVector[0] = Robot_statechart_last_state;
	stateConfVectorPosition = 0;
}

/* Default exit sequence for region main region */
void Robot_statechart::exseq_main_region()
{
	/* Default exit sequence for region main region */
	/* Handle exit of all possible states (of robot_statechart.main_region) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case main_region_not_driving_r1_stopped :
		{
			exseq_main_region_not_driving_r1_stopped();
			break;
		}
		case main_region_not_driving_r1_rotating :
		{
			exseq_main_region_not_driving_r1_rotating();
			break;
		}
		case main_region_driving_r1_driving_forwads :
		{
			exseq_main_region_driving_r1_driving_forwads();
			break;
		}
		case main_region_driving_r1_driving_backwards :
		{
			exseq_main_region_driving_r1_driving_backwards();
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
void Robot_statechart::exseq_main_region_not_driving_r1()
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of robot_statechart.main_region.not_driving.r1) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case main_region_not_driving_r1_stopped :
		{
			exseq_main_region_not_driving_r1_stopped();
			break;
		}
		case main_region_not_driving_r1_rotating :
		{
			exseq_main_region_not_driving_r1_rotating();
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
void Robot_statechart::exseq_main_region_driving_r1()
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of robot_statechart.main_region.driving.r1) at position 0... */
	switch(stateConfVector[ 0 ])
	{
		case main_region_driving_r1_driving_forwads :
		{
			exseq_main_region_driving_r1_driving_forwads();
			break;
		}
		case main_region_driving_r1_driving_backwards :
		{
			exseq_main_region_driving_r1_driving_backwards();
			break;
		}
		default: break;
	}
}

/* Default react sequence for initial entry  */
void Robot_statechart::react_main_region__entry_Default()
{
	/* Default react sequence for initial entry  */
	enseq_main_region_not_driving_default();
}

/* Default react sequence for initial entry  */
void Robot_statechart::react_main_region_not_driving_r1__entry_Default()
{
	/* Default react sequence for initial entry  */
	enseq_main_region_not_driving_r1_stopped_default();
}

sc_boolean Robot_statechart::react(const sc_boolean try_transition) {
	/* State machine reactions. */
	return false;
}

sc_boolean Robot_statechart::main_region_not_driving_react(const sc_boolean try_transition) {
	/* The reactions of state not_driving. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (((react(try_transition)) == (false)))
		{ 
			if ((((*(ifaceCtrl.ctrlUnit)).getCommand()) == (Forwards)))
			{ 
				exseq_main_region_not_driving();
				enseq_main_region_driving_r1_driving_forwads_default();
			}  else
			{
				did_transition = false;
			}
		} 
	} 
	if (((did_transition) == (false)))
	{ 
	} 
	return did_transition;
}

sc_boolean Robot_statechart::main_region_not_driving_r1_stopped_react(const sc_boolean try_transition) {
	/* The reactions of state stopped. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (((main_region_not_driving_react(try_transition)) == (false)))
		{ 
			if ((((*(ifaceCtrl.ctrlUnit)).getCommand()) == (Rotate)))
			{ 
				exseq_main_region_not_driving_r1_stopped();
				enseq_main_region_not_driving_r1_rotating_default();
			}  else
			{
				did_transition = false;
			}
		} 
	} 
	if (((did_transition) == (false)))
	{ 
	} 
	return did_transition;
}

sc_boolean Robot_statechart::main_region_not_driving_r1_rotating_react(const sc_boolean try_transition) {
	/* The reactions of state rotating. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (((main_region_not_driving_react(try_transition)) == (false)))
		{ 
			if ((((*(ifaceCtrl.ctrlUnit)).getCommand()) == (Stop)))
			{ 
				exseq_main_region_not_driving_r1_rotating();
				enseq_main_region_not_driving_r1_stopped_default();
			}  else
			{
				if ((((*(ifaceCtrl.ctrlUnit)).getCommand()) == (Backwards)))
				{ 
					exseq_main_region_not_driving();
					enseq_main_region_driving_r1_driving_backwards_default();
				}  else
				{
					did_transition = false;
				}
			}
		} 
	} 
	if (((did_transition) == (false)))
	{ 
	} 
	return did_transition;
}

sc_boolean Robot_statechart::main_region_driving_react(const sc_boolean try_transition) {
	/* The reactions of state driving. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (((react(try_transition)) == (false)))
		{ 
			if (((((*(ifaceCtrl.ctrlUnit)).getCommand()) == (Stop))) || ((((*(ifaceCtrl.ctrlUnit)).getCommand()) == (Rotate))))
			{ 
				exseq_main_region_driving();
				enseq_main_region_not_driving_default();
			}  else
			{
				did_transition = false;
			}
		} 
	} 
	if (((did_transition) == (false)))
	{ 
	} 
	return did_transition;
}

sc_boolean Robot_statechart::main_region_driving_r1_driving_forwads_react(const sc_boolean try_transition) {
	/* The reactions of state driving_forwads. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (((main_region_driving_react(try_transition)) == (false)))
		{ 
			if ((((*(ifaceCtrl.ctrlUnit)).getCommand()) == (Backwards)))
			{ 
				exseq_main_region_driving_r1_driving_forwads();
				enseq_main_region_driving_r1_driving_backwards_default();
			}  else
			{
				did_transition = false;
			}
		} 
	} 
	if (((did_transition) == (false)))
	{ 
	} 
	return did_transition;
}

sc_boolean Robot_statechart::main_region_driving_r1_driving_backwards_react(const sc_boolean try_transition) {
	/* The reactions of state driving_backwards. */
	sc_boolean did_transition = try_transition;
	if (try_transition)
	{ 
		if (((main_region_driving_react(try_transition)) == (false)))
		{ 
			if ((((*(ifaceCtrl.ctrlUnit)).getCommand()) == (Forwards)))
			{ 
				exseq_main_region_driving_r1_driving_backwards();
				enseq_main_region_driving_r1_driving_forwads_default();
			}  else
			{
				did_transition = false;
			}
		} 
	} 
	if (((did_transition) == (false)))
	{ 
	} 
	return did_transition;
}




