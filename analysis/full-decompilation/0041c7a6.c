
undefined4 __fastcall FUN_0041c7a6(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined **local_54 [3];
  undefined1 local_48 [64];
  int local_8;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar3 = 0xffffffcf;
  }
  else {
    uVar3 = 0;
  }
  FUN_004659fc(uVar3);
  iVar2 = FUN_00401f6f();
  if (iVar2 == 0) {
    cVar1 = (**(code **)(*param_1 + 0x20))();
    iVar2 = local_8;
    if ((cVar1 != '\0') && ((char)param_1[9] != '\0')) {
      (**(code **)(*param_1 + 0x1c))();
      iVar2 = param_1[2];
    }
    if ((((iVar2 == 0) && (cVar1 = (**(code **)(*param_1 + 0x20))(), cVar1 != '\0')) &&
        (param_1[8] == 0)) &&
       ((((char)param_1[9] != '\0' && (*(char *)((int)param_1 + 0x25) == '\0')) &&
        (0x27ff < *(int *)(param_1[6] + 0x14))))) {
      iVar2 = FUN_0041d667();
    }
    cVar1 = (**(code **)(*param_1 + 0x20))();
    if (((cVar1 != '\0') && (iVar2 == 0)) && ((char)param_1[9] != '\0')) {
      FUN_0041bde8(0x72736d70);
      iVar2 = FUN_0041baf1(0x72736d70,0,0);
      if ((iVar2 == 0) && (local_8 = FUN_0041e760(param_1[6],0x72736d70,0), local_8 != 0)) {
        FUN_0046f824(local_48,0,0x40);
        local_54[0] = &PTR_FUN_0066651c;
        FUN_0046f847(&DAT_006de560,0xffffffff);
        (**(code **)(*param_1 + 0x74))(local_8,0x72736d70,0,local_54,1);
        if ((param_1[2] == 0) &&
           ((((**(code **)(*param_1 + 0x7c))(local_8), param_1[2] == 0 &&
             (iVar2 = FUN_0041baf1(0x72736d70,0,0), iVar2 != 0)) && (*(int *)(iVar2 + 0xc) != -1))))
        {
          FUN_0041c6d8(-(uint)(param_1 != (int *)0x0) & (uint)(param_1 + 3),*(int *)(iVar2 + 0xc));
        }
      }
    }
    FUN_0041bd97();
    FUN_0041e4d9();
    iVar2 = param_1[6];
    if (iVar2 != 0) {
      FUN_0041c93d();
      FUN_006321f0(iVar2);
    }
    param_1[6] = 0;
    uVar3 = FUN_00413154();
    FUN_004659fc(uVar3);
  }
  else {
    uVar3 = FUN_00401f6f();
  }
  return uVar3;
}

