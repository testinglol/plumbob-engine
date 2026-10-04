
int __thiscall FUN_005c5930(int param_1,undefined4 *param_2,char param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_3 == '\0') {
    iVar2 = *(int *)(param_1 + 0x38);
  }
  else {
    uVar1 = *param_2;
    uVar3 = param_2[1];
    FUN_00462be8(param_2 + 2);
    uVar1 = FUN_005c64f0(uVar1,uVar3);
    uVar1 = FUN_005c64e0(uVar1);
    iVar2 = FUN_005c6ff0(uVar1);
  }
  if (iVar2 == *(int *)(param_1 + 0x38)) {
    if (*(int *)(param_1 + 0x38) == *(int *)(param_1 + 0x3c)) {
      FUN_005c6c10(*(int *)(param_1 + 0x38),param_2);
    }
    else {
      FUN_005c70e0();
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 0x18;
    }
    return (*(int *)(param_1 + 0x38) - *(int *)(param_1 + 0x34)) / 0x18 + -1;
  }
  return (iVar2 - *(int *)(param_1 + 0x34)) / 0x18;
}

