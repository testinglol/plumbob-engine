
undefined4 FUN_004e00a4(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  BOOL BVar2;
  _SYSTEM_INFO local_28;
  
  cVar1 = FUN_004e0015();
  if (((((cVar1 != '\0') && (param_1 != (int *)0x0)) && (param_2 != (int *)0x0)) &&
      ((BVar2 = IsBadReadPtr(param_1,0x10), BVar2 == 0 &&
       (BVar2 = IsBadReadPtr(param_2,0x10), BVar2 == 0)))) &&
     ((*param_1 == 0x50594f52 && (*param_2 == 0x50594f52)))) {
    if ((param_1[2] == 0) && (param_2[2] == 0)) {
      GetSystemInfo(&local_28);
      DAT_006f2218 = local_28.dwPageSize >> 10;
      FUN_004e06a7(param_3);
      FUN_004e0191(param_1,param_2);
      FUN_004e02a4(param_1,param_2,param_3);
      FUN_004e066d(param_3,&DAT_006c8578);
      FUN_004e0622(param_1,param_2,param_3,param_4);
      return 1;
    }
    FUN_004e066d(param_3,s_One_or_both_snapshots_has_alread_006c8e00);
  }
  return 0;
}

