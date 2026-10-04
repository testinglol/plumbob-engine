
bool __fastcall FUN_005fb499(int *param_1)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = 0;
  if (((int *)param_1[2] == (int *)0x0) || (DAT_006fed74 == (undefined4 *)0x0)) {
    bVar3 = true;
  }
  else {
    cVar1 = (**(code **)(*(int *)param_1[2] + 0x94))();
    if (cVar1 == '\0') {
      param_1[0xf] = 0;
    }
    else {
      iVar2 = (**(code **)*DAT_006fed74)(DAT_006fed74,&DAT_00677248,param_1 + 0xe);
      if (iVar2 != 0) {
        param_1[0xe] = 0;
        param_1[0xf] = 0;
      }
      param_1[0xf] = 1;
    }
    (**(code **)(*param_1 + 0x48))(param_1[3],param_1[4]);
    bVar3 = iVar2 == 0;
  }
  return bVar3;
}

