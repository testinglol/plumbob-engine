
void FUN_006388c5(undefined4 *param_1)

{
  DWORD DVar1;
  undefined4 uVar2;
  _TIME_ZONE_INFORMATION local_d0;
  _SYSTEMTIME local_24;
  _SYSTEMTIME local_14;
  
  GetLocalTime(&local_14);
  GetSystemTime(&local_24);
  if (local_24.wMinute == DAT_00703b18._2_2_) {
    if (local_24.wHour == (WORD)DAT_00703b18) {
      if (local_24.wDay == DAT_00703b14._2_2_) {
        if (local_24.wMonth == DAT_00703b10._2_2_) {
          if (local_24.wYear == (WORD)DAT_00703b10) goto LAB_0063896f;
        }
      }
    }
  }
  DVar1 = GetTimeZoneInformation(&local_d0);
  if (DVar1 == 0xffffffff) {
    DAT_00703b08 = 0xffffffff;
  }
  else if (((DVar1 == 2) && (local_d0.DaylightDate.wMonth != 0)) && (local_d0.DaylightBias != 0)) {
    DAT_00703b08 = 1;
  }
  else {
    DAT_00703b08 = 0;
  }
  DAT_00703b10._0_2_ = local_24.wYear;
  DAT_00703b10._2_2_ = local_24.wMonth;
  DAT_00703b14._0_2_ = local_24.wDayOfWeek;
  DAT_00703b14._2_2_ = local_24.wDay;
  DAT_00703b18._0_2_ = local_24.wHour;
  DAT_00703b18._2_2_ = local_24.wMinute;
  DAT_00703b1c._0_2_ = local_24.wSecond;
  DAT_00703b1c._2_2_ = local_24.wMilliseconds;
LAB_0063896f:
  uVar2 = FUN_00644c73(local_14.wYear,local_14.wMonth,local_14.wDay,local_14.wHour,local_14.wMinute,
                       local_14.wSecond,DAT_00703b08);
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = uVar2;
  }
  return;
}

