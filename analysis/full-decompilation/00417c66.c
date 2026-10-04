
void __thiscall FUN_00417c66(int *param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_1c;
  int local_18;
  undefined2 local_14;
  undefined2 local_12;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  cVar2 = (**(code **)(*param_1 + 0x28))();
  if (cVar2 == '\0') {
    uVar4 = 0xffffffcf;
  }
  else {
    uVar4 = 0;
  }
  FUN_004659fc(uVar4);
  iVar3 = FUN_00401f6f();
  if (iVar3 != 0) {
    return;
  }
  cVar2 = (**(code **)(*param_1 + 0x28))();
  if (cVar2 == '\0') {
    iVar3 = -0x31;
    goto LAB_00417d92;
  }
  cVar2 = (**(code **)(*param_1 + 0x20))();
  if (cVar2 == '\0') {
    iVar3 = -0x2d;
    goto LAB_00417d92;
  }
  iVar3 = FUN_00418360(param_1[6],param_2,&local_c,0);
  if (iVar3 == 0) {
    iVar3 = -99;
    goto LAB_00417d92;
  }
  FUN_004659fc(0);
  local_8 = FUN_00420096(param_2);
  piVar1 = (int *)(iVar3 + 8);
  if (*piVar1 == -1) {
LAB_00417d1a:
    FUN_00418073(&local_1c,local_8,piVar1);
  }
  else {
    FUN_004181b3(&local_1c,*piVar1);
    if (local_18 != local_8 + 0x10) {
      FUN_00418036(*piVar1);
      goto LAB_00417d1a;
    }
  }
  local_1c = local_c;
  local_14 = *(undefined2 *)(iVar3 + 4);
  local_12 = *(undefined2 *)(iVar3 + 6);
  local_10 = *(undefined4 *)(iVar3 + 0xc);
  iVar3 = FUN_00418223(&local_1c,*piVar1);
  if ((iVar3 == 0) && (iVar3 = FUN_004131a0(*piVar1 + 0x10), iVar3 == 0)) {
    uVar4 = FUN_00420048(param_2);
    iVar3 = FUN_00412f9f(uVar4,&local_8);
    FUN_0042004f(param_2);
    if (iVar3 == 0) {
      return;
    }
  }
LAB_00417d92:
  FUN_004659fc(iVar3);
  return;
}

