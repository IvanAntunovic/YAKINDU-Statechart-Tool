
#ifndef ROBOT_STATECHART_H_
#define ROBOT_STATECHART_H_


#include "..\src\ControlUnit.hpp"
#include "..\src\Logger.hpp"
#include "..\src\CleaningRobot.hpp"
#include "..\src\sc_types.h"
#include "..\src\StatemachineInterface.h"

/*! \file Header of the state machine 'robot_statechart'.
*/



/*! Define indices of states in the StateConfVector */
#define SCVI_MAIN_REGION_NOT_DRIVING 0
#define SCVI_MAIN_REGION_NOT_DRIVING_R1_STOPPED 0
#define SCVI_MAIN_REGION_NOT_DRIVING_R1_ROTATING 0
#define SCVI_MAIN_REGION_DRIVING 0
#define SCVI_MAIN_REGION_DRIVING_R1_DRIVING_FORWADS 0
#define SCVI_MAIN_REGION_DRIVING_R1_DRIVING_BACKWARDS 0

class Robot_statechart : public StatemachineInterface
{
	public:
		Robot_statechart();
		
		~Robot_statechart();
		
		/*! Enumeration of all states */ 
		typedef enum
		{
			Robot_statechart_last_state,
			main_region_not_driving,
			main_region_not_driving_r1_stopped,
			main_region_not_driving_r1_rotating,
			main_region_driving,
			main_region_driving_r1_driving_forwads,
			main_region_driving_r1_driving_backwards
		} Robot_statechartStates;
		
		static const sc_integer numStates = 6;
		
		//! Inner class for ctrl interface scope.
		class SCI_Ctrl
		{
			
			public:
				/*! Raises the in event 'userEvent' that is defined in the interface scope 'ctrl'. */
				void raise_userEvent(Command value);
				
				/*! Gets the value of the variable 'logger' that is defined in the interface scope 'ctrl'. */
				Logger get_logger() const;
				
				/*! Sets the value of the variable 'logger' that is defined in the interface scope 'ctrl'. */
				void set_logger(Logger value);
				
				/*! Gets the value of the variable 'controlUnit' that is defined in the interface scope 'ctrl'. */
				ControlUnit get_controlUnit() const;
				
				/*! Sets the value of the variable 'controlUnit' that is defined in the interface scope 'ctrl'. */
				void set_controlUnit(ControlUnit value);
				
				/*! Gets the value of the variable 'robotCtrl' that is defined in the interface scope 'ctrl'. */
				CleaningRobot get_robotCtrl() const;
				
				/*! Sets the value of the variable 'robotCtrl' that is defined in the interface scope 'ctrl'. */
				void set_robotCtrl(CleaningRobot value);
				
				
			private:
				friend class Robot_statechart;
				sc_boolean userEvent_raised;
				Command userEvent_value;
				Logger logger;
				ControlUnit controlUnit;
				CleaningRobot robotCtrl;
		};
		
		/*! Returns an instance of the interface class 'SCI_Ctrl'. */
		SCI_Ctrl* getSCI_Ctrl();
		
		
		/*
		 * Functions inherited from StatemachineInterface
		 */
		virtual void init();
		
		virtual void enter();
		
		virtual void exit();
		
		virtual void runCycle();
		
		/*!
		* Checks if the state machine is active (until 2.4.1 this method was used for states).
		* A state machine is active if it has been entered. It is inactive if it has not been entered at all or if it has been exited.
		*/
		virtual sc_boolean isActive() const;
		
		
		/*!
		* Checks if all active states are final. 
		* If there are no active states then the state machine is considered being inactive. In this case this method returns false.
		*/
		virtual sc_boolean isFinal() const;
		
		
		/*! Checks if the specified state is active (until 2.4.1 the used method for states was calles isActive()). */
		sc_boolean isStateActive(Robot_statechartStates state) const;
		
	protected:
	private:
		
		
		//! the maximum number of orthogonal states defines the dimension of the state configuration vector.
		static const sc_ushort maxOrthogonalStates = 1;
		
		
		Robot_statechartStates stateConfVector[maxOrthogonalStates];
		
		sc_ushort stateConfVectorPosition;
		
		SCI_Ctrl ifaceCtrl;
		
		// prototypes of all internal functions
		
		void enact_main_region_not_driving_r1_stopped();
		void enact_main_region_not_driving_r1_rotating();
		void enact_main_region_driving_r1_driving_forwads();
		void enact_main_region_driving_r1_driving_backwards();
		void enseq_main_region_not_driving_default();
		void enseq_main_region_not_driving_r1_stopped_default();
		void enseq_main_region_not_driving_r1_rotating_default();
		void enseq_main_region_driving_r1_driving_forwads_default();
		void enseq_main_region_driving_r1_driving_backwards_default();
		void enseq_main_region_default();
		void enseq_main_region_not_driving_r1_default();
		void exseq_main_region_not_driving();
		void exseq_main_region_not_driving_r1_stopped();
		void exseq_main_region_not_driving_r1_rotating();
		void exseq_main_region_driving();
		void exseq_main_region_driving_r1_driving_forwads();
		void exseq_main_region_driving_r1_driving_backwards();
		void exseq_main_region();
		void exseq_main_region_not_driving_r1();
		void exseq_main_region_driving_r1();
		void react_main_region__entry_Default();
		void react_main_region_not_driving_r1__entry_Default();
		sc_boolean react(const sc_boolean try_transition);
		sc_boolean main_region_not_driving_react(const sc_boolean try_transition);
		sc_boolean main_region_not_driving_r1_stopped_react(const sc_boolean try_transition);
		sc_boolean main_region_not_driving_r1_rotating_react(const sc_boolean try_transition);
		sc_boolean main_region_driving_react(const sc_boolean try_transition);
		sc_boolean main_region_driving_r1_driving_forwads_react(const sc_boolean try_transition);
		sc_boolean main_region_driving_r1_driving_backwards_react(const sc_boolean try_transition);
		void clearInEvents();
		void clearOutEvents();
		
};




#endif /* ROBOT_STATECHART_H_ */
