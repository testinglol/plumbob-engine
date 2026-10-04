
undefined4 __fastcall FUN_005f5039(int *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  if ((char)param_1[0x3f] != '\0') {
    FUN_00473496(DAT_006e5490);
    iVar3 = __ftol();
    iVar1 = param_1[0x3c];
    iVar4 = __ftol();
    if (iVar1 <= iVar4) {
      iVar3 = iVar3 + 1;
      iVar4 = 0;
    }
    param_1[0x3d] = -iVar4;
    param_1[0x3b] = iVar3;
    FUN_005f50ff();
    if (DAT_006e5490 < (uint)param_1[0x44]) {
      (**(code **)(*param_1 + 0x168))();
    }
    else {
      *(undefined1 *)(param_1 + 0x3f) = 0;
    }
  }
  cVar2 = (**(code **)(*(int *)param_1[0x17] + 0x20))(1);
  if (cVar2 != '\0') {
    (**(code **)(*(int *)param_1[0x17] + 0x40))(param_1[0x19],param_1 + 7,0);
    (**(code **)(*(int *)param_1[0x17] + 0x24))(1);
  }
  return 1;
}

