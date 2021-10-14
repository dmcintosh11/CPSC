/// @brief Unknown Aerial Phenomenon Explanatory Categorizer
/// @file UAPExpertSystem.cpp
/// @author Dylan McIntosh
/// @course CPSC-298-6 Programming in C++

#include <iostream>
#include <string>
#include <vector>

int main()
{

	std::cout << "Unknown Aerial Phenomenon (UAP) Explanatory Categorizer Expert System" << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;


	// //////////////////////////////////////////////////////////////////////////////////////////////////
	// Explanatory Categories
	// //////////////////////////////////////////////////////////////////////////////////////////////////

	const std::string strExplanatoryCategoryCommonplace = "Commonplace: Airborne Clutter, Natural Phenomena or Sensor Malfunction";
	const std::string strExplanatoryCategoryAdvancedSystem = "Advanced System: an advanced development system/prototype aircraft";
	const std::string strExplanatoryCategoryOther = "Other: An unknown phenomena. Unidentified; requires additional scientific knowledge to classify";
	const std::string strExplanatoryCategoryError = "Unable to characterize UAP Event; insufficient or contradictory information";

	// //////////////////////////////////////////////////////////////////////////////////////////////////
	// Reason strings associated with Decision variables
	// //////////////////////////////////////////////////////////////////////////////////////////////////

	// All reason strings may be preprended with "No " if the associated decision variable is false.
	const std::string strPrefixNo = "no ";

	// Ambient Conditions Reason strings
	const std::string strReasonBirdsInVicinity = "birds in vicinity";
	const std::string strReasonRecreationalUavActivityFeasible = "recreational UAV activity feasible";

	// Means of Detection Reason strings
	const std::string strReasonDetectedVisuallyOrPhotographed = "visual or electro-optical (E/O) camera detection";
	const std::string strReasonUapDetectedByRadar = "radar detection";
	const std::string strReasonDetectedByIR = "infrared (IR) sensor detection";

	// Unknown Aerial Phenomenon (UAP) Characteristics Reason strings
	const std::string strReasonUapAbruptManeuvers = "abrupt maneuvers performed by UAP";
	const std::string strReasonUnusualFlightCharacteristics = "unusual flight characteristics of UAP detected";
	const std::string strReasonUapSignatureManagement = "signature management performed by UAP";


	// Additional UAP Characteristics Reason strings (used only if detected visually or photographed using electro-optical camera)
	const std::string strReasonControlSurfacesVisable = "UAP control surfaces visible";
	const std::string strReasonUapDiscernableMeansOfPropulsion = "discernable UAP means of propulsion";
	const std::string strReasonUapObservedToUndulateOrChangeShape = "UAP undulation or change in shape observed";

	bool bUserWishesToContinue = true;

	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
	// TODO: INSERT BEGINNING OF WHILE LOOP HERE
	// The conditional expression for the while loop must involve the Boolean variable bUserWishesToContinue,
	// defined above:
	// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //

	while(bUserWishesToContinue)
	{
		std::cout << std::endl;
		std::cout << "UAP Event Questionnaire" << std::endl;;
		std::cout << "For all questions, please answer 1 for Yes and 0 for No." << std::endl;;
		std::cout << std::endl;

		bool bCategorized = false; // true when Expert System has identified an Explanatory Category to recommend.

		// //////////////////////////////////////////////////////////////////////////////////////////////////
		// Decision Variables
		// //////////////////////////////////////////////////////////////////////////////////////////////////

		// Ambient Conditions Decision Variables
		bool bBirdsInVicinity = false;
		bool bRecreationalUavActivityFeasible = false;

		// Means of Detection Decision Variables
		bool bUapDetectedVisuallyOrPhotographed = false;
		bool bUapDetectedByRadar = false;
		bool bUapDetectedByIR = false;

		// Unknown Aerial Phenomenon (UAP) Characteristics Decision Variables
		bool bUapAbruptManeuvers = false;
		bool bUapUnusualFlightCharacteristics = false;
		bool bUapSignatureManagement = false;

		// Unknown Aerial Phenomenon (UAP) Characteristics (only if visually sighted or photographed) Decision Variables
		bool bUapConrolSurfacesVisible = false;
		bool bUapDiscernableMeansOfPropulsion = false;
		bool bUapObservedToUndulateOrChangeShape = false;


		std::string strExplanatoryCategory = strExplanatoryCategoryError;



		// //////////////////////////////////////////////////////////////////////////////////////////////////
		// Consultation
		// //////////////////////////////////////////////////////////////////////////////////////////////////

		std::cout << "Were birds such as seaguls present in the vicinity or likely to have been present?" << std::endl;
		std::cin >> bBirdsInVicinity;

		std::cout << "Was recreational Unmanned Aerial Vehicle atcivity feasbile in the vicinity?" << std::endl;
		std::cin >> bRecreationalUavActivityFeasible;

		std::cout << "Was the UAP detected visually or photographed with an electro-optical camera?" << std::endl;
		std::cin >> bUapDetectedVisuallyOrPhotographed;

		std::cout << "Was the UAP detected by radar?" << std::endl;
		std::cin >> bUapDetectedByRadar;

		std::cout << "Was the UAP detected by an infra-red (IR) sensor (such as Forward-looking Infrared (FLIR))?" << std::endl;
		std::cin >> bUapDetectedByIR;

		std::cout << "Did the UAP perform abrupt maneuvers, beyond those achievable by known high-performance aircraft?" << std::endl;
		std::cin >> bUapAbruptManeuvers;

		std::cout << "Did the UAP exhibit unusual flight characteristics, but within the bounds of feasible aircraft performance?" << std::endl;
		std::cin >> bUapUnusualFlightCharacteristics;

		std::cout << "Did the UAP perform signature management (did its radar return or infrared signature change suddenly)?" << std::endl;
		std::cin >> bUapSignatureManagement;

		if (bUapDetectedVisuallyOrPhotographed)
		{
			std::cout << "When sighted or photographed, were control surfaces such as ailerons, flaps or a stabilator visible on the UAP?" << std::endl;
			std::cin >> bUapConrolSurfacesVisible;

			std::cout << "Was the UAP's means of propulsion discernable (for example, was jet exhaust observed)?" << std::endl;
			std::cin >> bUapDiscernableMeansOfPropulsion;

			std::cout << "Was the UAP observed to undulate or change shape?" << std::endl;
			std::cin >> bUapObservedToUndulateOrChangeShape;
		}
		std::cout << std::endl;
		std::cout << std::endl;

		// //////////////////////////////////////////////////////////////////////////////////////////////////
		// Rules
		// //////////////////////////////////////////////////////////////////////////////////////////////////

		// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
		// TODO: DEFINE A VARIABLE NAMED vecReason BY INSTANTIATING THE std::vector TEMPLATE CLASS.
		// The vector should have elements of the std::string data type. The declaration will have the following
		// form where you will replace with question marks (????) with the remainder of the declaration.
		// std::vector<?????> vecReason;
		// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //



		std::vector<std::string> vecReason;

		if (bUapDetectedVisuallyOrPhotographed)
		{
			vecReason.push_back(strReasonDetectedVisuallyOrPhotographed);

			if (bUapAbruptManeuvers)
			{
				vecReason.push_back(strReasonUapAbruptManeuvers);

				if (bUapDetectedByRadar || bUapDetectedByIR)
				{

					bUapDetectedByRadar ? vecReason.push_back(strReasonUapDetectedByRadar) : vecReason.push_back(strPrefixNo + strReasonUapDetectedByRadar);
					bUapDetectedByIR ? vecReason.push_back(strReasonDetectedByIR) : vecReason.push_back(strPrefixNo + strReasonDetectedByIR);

					// Rationale
					vecReason.push_back("UAP maneuverability inexplicable; detected by multiple sensor types");
					strExplanatoryCategory = strExplanatoryCategoryOther;
					bCategorized = true;
				}
				else
				{
					bUapDetectedByRadar ? vecReason.push_back(strReasonUapDetectedByRadar) : vecReason.push_back(strPrefixNo + strReasonUapDetectedByRadar);
					bUapDetectedByIR ? vecReason.push_back(strReasonDetectedByIR) : vecReason.push_back(strPrefixNo + strReasonDetectedByIR);

					// Rationale
					vecReason.push_back("UAP maneuverability inexplicable; possible optical illusion");
					strExplanatoryCategory = strExplanatoryCategoryError;
					bCategorized = true;
				}
			}
			else if (bUapUnusualFlightCharacteristics)
			{
				vecReason.push_back(strReasonUnusualFlightCharacteristics);

				if (bUapDetectedByRadar || bUapDetectedByIR)
				{
					bUapDetectedByRadar ? vecReason.push_back(strReasonUapDetectedByRadar) : vecReason.push_back(strPrefixNo + strReasonUapDetectedByRadar);
					bUapDetectedByIR ? vecReason.push_back(strReasonDetectedByIR) : vecReason.push_back(strPrefixNo + strReasonDetectedByIR);

					if (!bUapConrolSurfacesVisible || !bUapDiscernableMeansOfPropulsion)
					{
						if (!bUapConrolSurfacesVisible)
						{
							vecReason.push_back(strPrefixNo + strReasonControlSurfacesVisable);
						}
						if (!bUapDiscernableMeansOfPropulsion)
						{
							vecReason.push_back(strPrefixNo + strReasonUapDiscernableMeansOfPropulsion);
						}

						// Rationale
						vecReason.push_back("UAP maneuverability exteme but plausible; detected by multiple sensor types; inexlicable control or proplusion mechanism");
						strExplanatoryCategory = strExplanatoryCategoryOther;
						bCategorized = true;

					}
					else
					{
						bUapConrolSurfacesVisible ? vecReason.push_back(strReasonControlSurfacesVisable) : vecReason.push_back(strPrefixNo + strReasonControlSurfacesVisable);
						bUapDiscernableMeansOfPropulsion ? vecReason.push_back(strReasonUapDiscernableMeansOfPropulsion) : vecReason.push_back(strPrefixNo + strReasonUapDiscernableMeansOfPropulsion);

						// Rationale
						vecReason.push_back("UAP maneuverability exteme but plausible; detected by multiple sensor types; control and propulsion plausible");
						strExplanatoryCategory = strExplanatoryCategoryAdvancedSystem;
						bCategorized = true;

					}
				}
				else
				{
					vecReason.push_back(strPrefixNo + strReasonUapDetectedByRadar);
					vecReason.push_back(strPrefixNo + strReasonDetectedByIR);

					if (bUapObservedToUndulateOrChangeShape && bBirdsInVicinity)
					{
						vecReason.push_back(strReasonUapObservedToUndulateOrChangeShape);
						vecReason.push_back(strReasonBirdsInVicinity);

						// Flocks of birds can show up on radar and IR and the mass appears to change shape or undulate when viewed as a whole.
						// Birds don't always show on radar though if flock is small.
						vecReason.push_back("UAP maneuverability exteme but plausible; detected only visually; UAP changes shape or undulates; birds in vicinity");
						strExplanatoryCategory = strExplanatoryCategoryCommonplace;
						bCategorized = true;
					}
					else if (bRecreationalUavActivityFeasible)
					{

						bUapObservedToUndulateOrChangeShape ? vecReason.push_back(strReasonUapObservedToUndulateOrChangeShape) : vecReason.push_back(strPrefixNo + strReasonUapObservedToUndulateOrChangeShape);
						bBirdsInVicinity ? vecReason.push_back(strReasonBirdsInVicinity) : vecReason.push_back(strPrefixNo + strReasonBirdsInVicinity);

						vecReason.push_back(strReasonRecreationalUavActivityFeasible);
						vecReason.push_back("UAP maneuverability exteme but plausible; detected visually; recreational UAVs plausible in vicinity");
						strExplanatoryCategory = strExplanatoryCategoryAdvancedSystem;
						bCategorized = true;
					}
				}
			}
			else
			{
				if (!bUapConrolSurfacesVisible || !bUapDiscernableMeansOfPropulsion)
				{
					if (!bUapConrolSurfacesVisible)
					{
						vecReason.push_back(strPrefixNo + strReasonControlSurfacesVisable);
					}
					if (!bUapDiscernableMeansOfPropulsion)
					{
						vecReason.push_back(strPrefixNo + strReasonUapDiscernableMeansOfPropulsion);
					}

					// Rationale
					vecReason.push_back("UAP maneuverability exteme but plausible; detected by multiple sensor types; inexlicable control or proplusion mechanism");
					strExplanatoryCategory = strExplanatoryCategoryOther;
					bCategorized = true;
				}
				else
				{
					vecReason.push_back("UAP exhibits no unusual characteristics; not considered by UAP Task Force");
					strExplanatoryCategory = strExplanatoryCategoryError;
					bCategorized = true;
				}
			}
		}
		else
		{
			vecReason.push_back(strPrefixNo + strReasonDetectedVisuallyOrPhotographed);

			if (bUapAbruptManeuvers)
			{
				vecReason.push_back(strReasonUapAbruptManeuvers);

				// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
				// TODO: IN THE FOLLOWING IF BLOCK, ENTER THE BLOCK IF THE UAP WAS BOTH DETECTED BY RADAR
				// (bUapDetectedByRadar) AND DETECTED BY INFRARED (bUapDetectedByIR).
				// At the start of the block (after the { character), add two reasons to the vecReason vector using
				// the push_back() method. The first reason is that the UAP was detected by radar
				// (strReasonUapDetectedByRadar) and the second reason is that the UAP was detected by Infra-red
				// (strReasonDetectedByIR).
				// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //

				if (bUapDetectedByRadar && bUapDetectedByIR)
				{
					 vecReason.push_back(strReasonUapDetectedByRadar);
					 vecReason.push_back(strReasonDetectedByIR);

					// Rationale
					vecReason.push_back("UAP maneuverability inexplicable; detected by multiple sensor types");
					strExplanatoryCategory = strExplanatoryCategoryOther;
					bCategorized = true;
				}
				else
				{
					bUapDetectedByRadar ? vecReason.push_back(strReasonUapDetectedByRadar) : vecReason.push_back(strPrefixNo + strReasonUapDetectedByRadar);
					bUapDetectedByIR ? vecReason.push_back(strReasonDetectedByIR) : vecReason.push_back(strPrefixNo + strReasonDetectedByIR);

					// Rationale
					vecReason.push_back("UAP maneuverability inexplicable; possible sensor anomaly");
					strExplanatoryCategory = strExplanatoryCategoryError;
					bCategorized = true;
				}
			}
			else if (bUapUnusualFlightCharacteristics)
			{
				vecReason.push_back(strReasonUnusualFlightCharacteristics);

				if (bUapDetectedByRadar && bUapDetectedByIR)
				{
					vecReason.push_back(strReasonUapDetectedByRadar);
					vecReason.push_back(strReasonDetectedByIR);

					if (bUapSignatureManagement)
					{
						vecReason.push_back(strReasonUapSignatureManagement);
						// Rationale
						vecReason.push_back("UAP maneuverability exteme but plausible; detected by multiple sensor types and employs signature management");
						strExplanatoryCategory = strExplanatoryCategoryAdvancedSystem;
						bCategorized = true;
					}
					else
					{
						vecReason.push_back(strPrefixNo + strReasonUapSignatureManagement);

						if (bRecreationalUavActivityFeasible)
						{
							vecReason.push_back(strReasonRecreationalUavActivityFeasible);
							vecReason.push_back("UAP maneuverability exteme but plausible; detected by multiple sensor types and does not employ signature managment; recreational UAVs plausible in vicinity");
							strExplanatoryCategory = strExplanatoryCategoryAdvancedSystem;
							bCategorized = true;
						}
						else if (bBirdsInVicinity)
						{
							vecReason.push_back(strPrefixNo + strReasonRecreationalUavActivityFeasible);
							vecReason.push_back(strReasonBirdsInVicinity);
							// Rationale
							vecReason.push_back("UAP maneuverability exteme but plausible; detected by multiple sensor types and does not employ signature managment, recreational UAV implausible, birds in vicintity");
							strExplanatoryCategory = strExplanatoryCategoryAdvancedSystem;
							bCategorized = true;
						}
					}
				}
				else
				{
					bUapDetectedByRadar ? vecReason.push_back(strReasonUapDetectedByRadar) : vecReason.push_back(strPrefixNo + strReasonUapDetectedByRadar);
					bUapDetectedByIR ? vecReason.push_back(strReasonDetectedByIR) : vecReason.push_back(strPrefixNo + strReasonDetectedByIR);

					// Rationale
					vecReason.push_back("UAP maneuverability explicable; possible sensor anomaly");
					strExplanatoryCategory = strExplanatoryCategoryError;
					bCategorized = true;
				}
			}
			else
			{
				vecReason.push_back("UAP exhibits no unusual characteristics; not considered by UAP Task Force");
				strExplanatoryCategory = strExplanatoryCategoryError;
				bCategorized = true;
			}
		}

		std::cout << "Rules Engine Status: successfully categorized: " << bCategorized << std::endl;
		std::cout << "-----------------------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
		// //////////////////////////////////////////////////////////////////////////////////////////////////
		// Recommendation
		// //////////////////////////////////////////////////////////////////////////////////////////////////
		std::cout << "Explanatory Category Recommendation: " << strExplanatoryCategory << std::endl;

		std::cout << std::endl;


		// //////////////////////////////////////////////////////////////////////////////////////////////////
		// Explanation of Recommendation
		// //////////////////////////////////////////////////////////////////////////////////////////////////

		std::cout << "Reason: " << std::endl;

		// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
		// TODO: ITERATE OVER THE vecReason VECTOR AND EMIT STRINGS TO STANDARD OUTPUT IN ORDER
		// Use a for loop; use the vector size() function and the vector at() function as well as std::cout.
		// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //


		for (int i = 0; i < vecReason.size(); i++) {
			std::cout << vecReason.at(i) << std::endl;
		}



		// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
		// TODO: QUERY USER IF THEY WISH TO ENTER DATA FOR ANOTHER UAP EVENT
		// Prompt user using std::cout; collect input from user using std::cin into char variable cUserResponse;
		// allow user to type either 'Y' or 'y' to continue. Any other character is considered 'n'.
		// Use an OR operator (or, ||) and the NOT operator (!) in your solution.
		// ITERATE AGAIN THROUGH WHILE LOOP OR TERMINATE PROGRAM BASED ON USER RESPONSE
		// Alter value of variable bUserWishesToContinue to terminate while loop if user response requires.
		// /\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\ //
		std::cout << std::endl;
		std::cout << "Do you wish to analyze another UAP Event (y/n)?" << std::endl;
		char cUserResponse = 'n';
		 std::cin >> cUserResponse;
		  if(cUserResponse == 'y' || cUserResponse == 'Y')
		  {
		     bUserWishesToContinue = true;
		  } else {

				bUserWishesToContinue = false;
			}


	} // end while loop

	std::cout << std::endl;
	std::cout << "UAP Expert System terminated normally" << std::endl;
	std::cout << std::endl;
}
