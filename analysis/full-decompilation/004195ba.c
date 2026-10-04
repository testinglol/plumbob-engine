
undefined4 __fastcall FUN_004195ba(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined **local_54 [3];
  undefined1 local_48 [64];
  int local_8;
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar4 = 0xffffffcf;
  }
  else {
    uVar4 = 0;
  }
  FUN_004659fc(uVar4);
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
        (0x27ff < *(int *)(param_1[6] + 0xc))))) {
      iVar2 = FUN_0041a69a();
    }
    cVar1 = (**(code **)(*param_1 + 0x20))();
    if (((cVar1 != '\0') && (iVar2 == 0)) && ((char)param_1[9] != '\0')) {
      FUN_00418f91(0x72736d70);
      iVar2 = FUN_00418d1a(0x72736d70,0,0);
      if ((iVar2 == 0) && (local_8 = FUN_0041ad47(param_1[6],0x72736d70,0), local_8 != 0)) {
        FUN_0046f824(local_48,0,0x40);
        local_54[0] = &PTR_FUN_0066651c;
        FUN_0046f847(&DAT_006de560,0xffffffff);
        (**(code **)(*param_1 + 0x74))(local_8,0x72736d70,0,local_54,1);
        if ((param_1[2] == 0) &&
           ((((**(code **)(*param_1 + 0x7c))(local_8), param_1[2] == 0 &&
             (piVar3 = (int *)FUN_00418d1a(0x72736d70,0,0), piVar3 != (int *)0x0)) &&
            (*piVar3 != -1)))) {
          FUN_0041950d(-(uint)(param_1 != (int *)0x0) & (uint)(param_1 + 3),*piVar3);
        }
      }
    }
    FUN_00418f5f();
    FUN_0041a84b(*(undefined4 *)param_1[6],((undefined4 *)param_1[6])[1]);
    iVar2 = param_1[6];
    if (iVar2 != 0) {
      thunk_FUN_0041a77f();
      FUN_006321f0(iVar2);
    }
    param_1[6] = 0;
    uVar4 = FUN_00413154();
    FUN_004659fc(uVar4);
  }
  else {
    uVar4 = FUN_00401f6f();
  }
  return uVar4;
}

