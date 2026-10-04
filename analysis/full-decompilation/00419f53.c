
void __thiscall FUN_00419f53(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 local_5c;
  int local_58;
  undefined2 local_54;
  undefined2 local_52;
  char local_50 [63];
  undefined1 local_11;
  undefined4 local_10;
  int local_c;
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
  if (iVar2 != 0) {
    return;
  }
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    iVar2 = -0x31;
    goto LAB_0041a08d;
  }
  cVar1 = (**(code **)(*param_1 + 0x20))();
  if (cVar1 == '\0') {
    iVar2 = -0x2d;
    goto LAB_0041a08d;
  }
  piVar3 = (int *)FUN_00418e2d(param_2,&local_10,0);
  if (piVar3 == (int *)0x0) {
    iVar2 = -99;
    goto LAB_0041a08d;
  }
  FUN_004659fc(0);
  local_8 = FUN_00420096(param_2);
  if (*piVar3 == -1) {
LAB_0041a001:
    FUN_0041a386(&local_5c,local_8,piVar3);
  }
  else {
    FUN_0041a545(&local_5c,*piVar3);
    if (local_58 != local_8 + 0x4c) {
      FUN_0041a346(*piVar3);
      goto LAB_0041a001;
    }
  }
  local_5c = local_10;
  local_54 = (undefined2)piVar3[1];
  local_52 = (undefined2)piVar3[2];
  _strncpy(local_50,(char *)piVar3[5],0x3f);
  local_11 = 0;
  iVar2 = FUN_0041a5ac(&local_5c,*piVar3);
  if ((iVar2 == 0) && (iVar2 = FUN_004131a0(*piVar3 + 0x4c), iVar2 == 0)) {
    uVar4 = FUN_00420048(param_2);
    local_c = FUN_00412f9f(uVar4,&local_8);
    FUN_0042004f(param_2);
    iVar2 = local_c;
    if (local_c == 0) {
      *(short *)((int)piVar3 + 10) = (short)piVar3[2];
      FUN_004131cb();
      return;
    }
  }
LAB_0041a08d:
  FUN_004659fc(iVar2);
  return;
}

