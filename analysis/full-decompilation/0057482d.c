
void __thiscall FUN_0057482d(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  uVar1 = *(undefined4 *)(param_2 + 4);
  local_8 = param_1;
  FUN_0057488f(uVar1,&param_3,&local_8);
  piVar2 = (int *)FUN_00573466(uVar1);
  if (*(int *)(param_1 + 0x114) == 0) {
    (**(code **)(*piVar2 + 0x40))(param_3);
  }
  else {
    iVar3 = param_3 + -1;
    if (iVar3 < 0) {
      iVar3 = 1;
    }
    (**(code **)(*piVar2 + 0x40))(iVar3);
  }
  (**(code **)(*piVar2 + 0x48))(local_8);
  return;
}

