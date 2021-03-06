#ifndef CDT_CORE_VARIADIC_H
#define CDT_CORE_VARIADIC_H

#include <cstdarg>

#include "macro.h"

/* Here, 64 is considered the maximum number of arg authorized */
#define VARIADIC_SEQ		                  63,62,61,60, \
							59,58,57,56,55,54,53,52,51,50, \
							49,48,47,46,45,44,43,42,41,40, \
							39,38,37,36,35,34,33,32,31,30, \
							29,28,27,26,25,24,23,22,21,20, \
							19,18,17,16,15,14,13,12,11,10, \
							 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define VARIADIC_COUNT(args...) VARIADIC_COUNT_(args, VARIADIC_SEQ)
#define VARIADIC_COUNT_(args...) VARIADIC_COUNT_NBR(args)
#define VARIADIC_COUNT_NBR(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
							_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
							_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
							_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
							_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
							_50,_51,_52,_53,_54,_55,_56,_57,_58,_59, \
							_60,_61,_62,_63, N,_...) N

#define PROCESS_FOREACH(T, VARNAME, PROCESS, args...) \
	struct UNIQUE_NAME(VARNAME) { \
		static void process(T VARNAME) { \
			PROCESS \
		}; \
	}; \
	cdt::variadic_helper<T>(&UNIQUE_NAME(VARNAME)::process, VARIADIC_COUNT(args), args);

#define PROCESS_FOREACH_LOOP(T, VARNAME, PROCESS, args...) \
	T UNIQUE_NAME(VARNAME)[] = {args}; \
	int UNIQUE_NAME(nbr) = sizeof(UNIQUE_NAME(VARNAME)) / sizeof(T); \
	for (int UNIQUE_NAME(i) = 0; UNIQUE_NAME(i) < UNIQUE_NAME(nbr) ; UNIQUE_NAME(i)++) { \
		T VARNAME = UNIQUE_NAME(VARNAME)[UNIQUE_NAME(i)]; \
		PROCESS; \
	}

#define VARIADIC_GET_1(		 _1,_...)									_1
#define VARIADIC_GET_2(		 _1, _2,_...)								_2
#define VARIADIC_GET_3(		 _1, _2, _3,_...)							_3
#define VARIADIC_GET_4(		 _1, _2, _3, _4,_...)						_4
#define VARIADIC_GET_5(		 _1, _2, _3, _4, _5,_...)					_5
#define VARIADIC_GET_6(		 _1, _2, _3, _4, _5, _6,_...)				_6
#define VARIADIC_GET_7(		 _1, _2, _3, _4, _5, _6, _7,_...) 			_7
#define VARIADIC_GET_8(		 _1, _2, _3, _4, _5, _6, _7, _8,_...)		_8
#define VARIADIC_GET_9(		 _1, _2, _3, _4, _5, _6, _7, _8, _9,_...)	_9
#define VARIADIC_GET_10(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_...)										_10
#define VARIADIC_GET_11(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_...)									_11
#define VARIADIC_GET_12(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_...)								_12
#define VARIADIC_GET_13(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_...)							_13
#define VARIADIC_GET_14(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_...)						_14
#define VARIADIC_GET_15(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_...)					_15
#define VARIADIC_GET_16(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_...)				_16
#define VARIADIC_GET_17(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_...) 			_17
#define VARIADIC_GET_18(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_...)		_18
#define VARIADIC_GET_19(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_...)	_19
#define VARIADIC_GET_20(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_...)										_20
#define VARIADIC_GET_21(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_...)									_21
#define VARIADIC_GET_22(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_...)								_22
#define VARIADIC_GET_23(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_...)							_23
#define VARIADIC_GET_24(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_...)						_24
#define VARIADIC_GET_25(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_...)					_25
#define VARIADIC_GET_26(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_...)				_26
#define VARIADIC_GET_27(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_...) 			_27
#define VARIADIC_GET_28(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_...)		_28
#define VARIADIC_GET_29(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_...)	_29
#define VARIADIC_GET_30(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_...)										_30
#define VARIADIC_GET_31(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_...)									_31
#define VARIADIC_GET_32(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_...)								_32
#define VARIADIC_GET_33(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_...)							_33
#define VARIADIC_GET_34(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_...)						_34
#define VARIADIC_GET_35(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_...)					_35
#define VARIADIC_GET_36(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_...)				_36
#define VARIADIC_GET_37(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_...) 			_37
#define VARIADIC_GET_38(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_...)		_38
#define VARIADIC_GET_39(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39,_...)	_39
#define VARIADIC_GET_40(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_...)										_40
#define VARIADIC_GET_41(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_...)									_41
#define VARIADIC_GET_42(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_...)								_42
#define VARIADIC_GET_43(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_...)							_43
#define VARIADIC_GET_44(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_...)						_44
#define VARIADIC_GET_45(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_...)					_45
#define VARIADIC_GET_46(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_...)				_46
#define VARIADIC_GET_47(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_...) 			_47
#define VARIADIC_GET_48(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_...)		_48
#define VARIADIC_GET_49(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49,_...)	_49
#define VARIADIC_GET_50(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
						_50,_...)										_50
#define VARIADIC_GET_51(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
						_50,_51,_...)									_51
#define VARIADIC_GET_52(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
						_50,_51,_52,_...)								_52
#define VARIADIC_GET_53(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
						_50,_51,_52,_53,_...)							_53
#define VARIADIC_GET_54(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
						_50,_51,_52,_53,_54,_...)						_54
#define VARIADIC_GET_55(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
						_50,_51,_52,_53,_54,_55,_...)					_55
#define VARIADIC_GET_56(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
						_50,_51,_52,_53,_54,_55,_56,_...)				_56
#define VARIADIC_GET_57(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
						_50,_51,_52,_53,_54,_55,_56,_57,_...) 			_57
#define VARIADIC_GET_58(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
						_50,_51,_52,_53,_54,_55,_56,_57,_58,_...) 		_58
#define VARIADIC_GET_59(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
						_50,_51,_52,_53,_54,_55,_56,_57,_58,_59,_...)	_59
#define VARIADIC_GET_60(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
						_50,_51,_52,_53,_54,_55,_56,_57,_58,_59, \
						_60,_...)										_60
#define VARIADIC_GET_61(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
						_50,_51,_52,_53,_54,_55,_56,_57,_58,_59, \
						_60,_61,_...)									_61
#define VARIADIC_GET_62(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
						_50,_51,_52,_53,_54,_55,_56,_57,_58,_59, \
						_60,_61,_62,_...)								_62
#define VARIADIC_GET_63(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
						_50,_51,_52,_53,_54,_55,_56,_57,_58,_59, \
						_60,_61,_62,_63,_...)							_63
#define VARIADIC_GET_64(	 _1, _2, _3, _4, _5, _6, _7, _8, _9, \
						_10,_11,_12,_13,_14,_15,_16,_17,_18,_19, \
						_20,_21,_22,_23,_24,_25,_26,_27,_28,_29, \
						_30,_31,_32,_33,_34,_35,_36,_37,_38,_39, \
						_40,_41,_42,_43,_44,_45,_46,_47,_48,_49, \
						_50,_51,_52,_53,_54,_55,_56,_57,_58,_59, \
						_60,_61,_62,_63,_64,_...)						_64

#define FOREACH(CALLBACK, args...) CONCAT(FOREACH_, VARIADIC_COUNT(args))(CALLBACK, args)
#define FOREACH_(CALLBACK, X, args...) CALLBACK(X); FOREACH_63(CALLBACK, args)
#define FOREACH_63(CALLBACK, X, args...) CALLBACK(X); FOREACH_62(CALLBACK, args)
#define FOREACH_62(CALLBACK, X, args...) CALLBACK(X); FOREACH_61(CALLBACK, args)
#define FOREACH_61(CALLBACK, X, args...) CALLBACK(X); FOREACH_60(CALLBACK, args)
#define FOREACH_60(CALLBACK, X, args...) CALLBACK(X); FOREACH_59(CALLBACK, args)
#define FOREACH_59(CALLBACK, X, args...) CALLBACK(X); FOREACH_58(CALLBACK, args)
#define FOREACH_58(CALLBACK, X, args...) CALLBACK(X); FOREACH_57(CALLBACK, args)
#define FOREACH_57(CALLBACK, X, args...) CALLBACK(X); FOREACH_56(CALLBACK, args)
#define FOREACH_56(CALLBACK, X, args...) CALLBACK(X); FOREACH_55(CALLBACK, args)
#define FOREACH_55(CALLBACK, X, args...) CALLBACK(X); FOREACH_54(CALLBACK, args)
#define FOREACH_54(CALLBACK, X, args...) CALLBACK(X); FOREACH_53(CALLBACK, args)
#define FOREACH_53(CALLBACK, X, args...) CALLBACK(X); FOREACH_52(CALLBACK, args)
#define FOREACH_52(CALLBACK, X, args...) CALLBACK(X); FOREACH_51(CALLBACK, args)
#define FOREACH_51(CALLBACK, X, args...) CALLBACK(X); FOREACH_50(CALLBACK, args)
#define FOREACH_50(CALLBACK, X, args...) CALLBACK(X); FOREACH_49(CALLBACK, args)
#define FOREACH_49(CALLBACK, X, args...) CALLBACK(X); FOREACH_48(CALLBACK, args)
#define FOREACH_48(CALLBACK, X, args...) CALLBACK(X); FOREACH_47(CALLBACK, args)
#define FOREACH_47(CALLBACK, X, args...) CALLBACK(X); FOREACH_46(CALLBACK, args)
#define FOREACH_46(CALLBACK, X, args...) CALLBACK(X); FOREACH_45(CALLBACK, args)
#define FOREACH_45(CALLBACK, X, args...) CALLBACK(X); FOREACH_44(CALLBACK, args)
#define FOREACH_44(CALLBACK, X, args...) CALLBACK(X); FOREACH_43(CALLBACK, args)
#define FOREACH_43(CALLBACK, X, args...) CALLBACK(X); FOREACH_42(CALLBACK, args)
#define FOREACH_42(CALLBACK, X, args...) CALLBACK(X); FOREACH_41(CALLBACK, args)
#define FOREACH_41(CALLBACK, X, args...) CALLBACK(X); FOREACH_40(CALLBACK, args)
#define FOREACH_40(CALLBACK, X, args...) CALLBACK(X); FOREACH_39(CALLBACK, args)
#define FOREACH_39(CALLBACK, X, args...) CALLBACK(X); FOREACH_38(CALLBACK, args)
#define FOREACH_38(CALLBACK, X, args...) CALLBACK(X); FOREACH_37(CALLBACK, args)
#define FOREACH_37(CALLBACK, X, args...) CALLBACK(X); FOREACH_36(CALLBACK, args)
#define FOREACH_36(CALLBACK, X, args...) CALLBACK(X); FOREACH_35(CALLBACK, args)
#define FOREACH_35(CALLBACK, X, args...) CALLBACK(X); FOREACH_34(CALLBACK, args)
#define FOREACH_34(CALLBACK, X, args...) CALLBACK(X); FOREACH_33(CALLBACK, args)
#define FOREACH_33(CALLBACK, X, args...) CALLBACK(X); FOREACH_32(CALLBACK, args)
#define FOREACH_32(CALLBACK, X, args...) CALLBACK(X); FOREACH_31(CALLBACK, args)
#define FOREACH_31(CALLBACK, X, args...) CALLBACK(X); FOREACH_30(CALLBACK, args)
#define FOREACH_30(CALLBACK, X, args...) CALLBACK(X); FOREACH_29(CALLBACK, args)
#define FOREACH_29(CALLBACK, X, args...) CALLBACK(X); FOREACH_28(CALLBACK, args)
#define FOREACH_28(CALLBACK, X, args...) CALLBACK(X); FOREACH_27(CALLBACK, args)
#define FOREACH_27(CALLBACK, X, args...) CALLBACK(X); FOREACH_26(CALLBACK, args)
#define FOREACH_26(CALLBACK, X, args...) CALLBACK(X); FOREACH_25(CALLBACK, args)
#define FOREACH_25(CALLBACK, X, args...) CALLBACK(X); FOREACH_24(CALLBACK, args)
#define FOREACH_24(CALLBACK, X, args...) CALLBACK(X); FOREACH_23(CALLBACK, args)
#define FOREACH_23(CALLBACK, X, args...) CALLBACK(X); FOREACH_22(CALLBACK, args)
#define FOREACH_22(CALLBACK, X, args...) CALLBACK(X); FOREACH_21(CALLBACK, args)
#define FOREACH_21(CALLBACK, X, args...) CALLBACK(X); FOREACH_20(CALLBACK, args)
#define FOREACH_20(CALLBACK, X, args...) CALLBACK(X); FOREACH_19(CALLBACK, args)
#define FOREACH_19(CALLBACK, X, args...) CALLBACK(X); FOREACH_18(CALLBACK, args)
#define FOREACH_18(CALLBACK, X, args...) CALLBACK(X); FOREACH_17(CALLBACK, args)
#define FOREACH_17(CALLBACK, X, args...) CALLBACK(X); FOREACH_16(CALLBACK, args)
#define FOREACH_16(CALLBACK, X, args...) CALLBACK(X); FOREACH_15(CALLBACK, args)
#define FOREACH_15(CALLBACK, X, args...) CALLBACK(X); FOREACH_14(CALLBACK, args)
#define FOREACH_14(CALLBACK, X, args...) CALLBACK(X); FOREACH_13(CALLBACK, args)
#define FOREACH_13(CALLBACK, X, args...) CALLBACK(X); FOREACH_12(CALLBACK, args)
#define FOREACH_12(CALLBACK, X, args...) CALLBACK(X); FOREACH_11(CALLBACK, args)
#define FOREACH_11(CALLBACK, X, args...) CALLBACK(X); FOREACH_10(CALLBACK, args)
#define FOREACH_10(CALLBACK, X, args...) CALLBACK(X); FOREACH_9(CALLBACK, args)
#define FOREACH_9(CALLBACK, X, args...) CALLBACK(X); FOREACH_8(CALLBACK, args)
#define FOREACH_8(CALLBACK, X, args...) CALLBACK(X); FOREACH_7(CALLBACK, args)
#define FOREACH_7(CALLBACK, X, args...) CALLBACK(X); FOREACH_6(CALLBACK, args)
#define FOREACH_6(CALLBACK, X, args...) CALLBACK(X); FOREACH_5(CALLBACK, args)
#define FOREACH_5(CALLBACK, X, args...) CALLBACK(X); FOREACH_4(CALLBACK, args)
#define FOREACH_4(CALLBACK, X, args...) CALLBACK(X); FOREACH_3(CALLBACK, args)
#define FOREACH_3(CALLBACK, X, args...) CALLBACK(X); FOREACH_2(CALLBACK, args)
#define FOREACH_2(CALLBACK, X, args...) CALLBACK(X); FOREACH_1(CALLBACK, args)
#define FOREACH_1(CALLBACK, X) CALLBACK(X)

namespace cdt {
	
template<typename T>
static inline void variadic_helper(void(*process)(T), unsigned int nbr, ...) {
	va_list ap;
	va_start(ap, nbr);
	for (unsigned int i = 0; i < nbr; i++) {
		T arg = va_arg(ap, T);
		process(arg);
	}
	va_end(ap);
}

}


#endif // CDT_CORE_VARIADIC_H
