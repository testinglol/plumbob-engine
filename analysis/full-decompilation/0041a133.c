
void __thiscall FUN_0041a133(int *param_1,undefined4 param_2,short param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 local_94 [64];
  undefined1 local_54 [8];
  undefined2 local_4c;
  char local_48 [63];
  undefined1 local_9;
  undefined1 local_8 [4];
  
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar6 = 0xffffffcf;
  }
  else {
    uVar6 = 0;
  }
  FUN_004659fc(uVar6);
  iVar2 = FUN_00401f6f();
  if (iVar2 != 0) {
    return;
  }
  piVar3 = (int *)FUN_00418e2d(param_2,local_8,0);
  if (piVar3 == (int *)0x0) {
    iVar2 = -99;
  }
  else {
    FUN_0046f824(local_94,0,0x40);
    iVar4 = (int)param_3;
    iVar2 = piVar3[1];
    if (iVar2 != iVar4) {
      piVar3[1] = iVar4;
    }
    iVar5 = FUN_0046f93d(piVar3 + 4);
    if (iVar5 != 0) {
      FUN_0046f8e4(param_4);
    }
    if ((iVar5 == 0 && iVar2 == iVar4) || (*piVar3 == -1)) goto LAB_0041a22e;
    iVar2 = FUN_0041a545(local_54,*piVar3);
    if (iVar2 == 0) {
      local_4c = (undefined2)piVar3[1];
      _strncpy(local_48,(char *)piVar3[5],0x3f);
      local_9 = 0;
      FUN_0041a5ac(local_54,*piVar3);
    }
  }
  FUN_004659fc(iVar2);
LAB_0041a22e:
  FUN_004131cb();
  return;
}

