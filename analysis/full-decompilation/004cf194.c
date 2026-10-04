
void __thiscall FUN_004cf194(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = FUN_0043acf5(param_2);
  if (iVar2 == 0) {
    FUN_004cf136(7,0xffffffff);
  }
  else {
    piVar3 = (int *)FUN_00484901(7);
    uVar1 = *(undefined4 *)(iVar2 + 0xa8);
    (**(code **)(*piVar3 + 0x18))();
    FUN_004cf169(piVar3,uVar1);
    iVar2 = FUN_00487c19(iVar2);
    *(int *)(param_1 + 0x50) = iVar2;
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x50) = uVar1;
    }
  }
  return;
}

