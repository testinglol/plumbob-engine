
void __thiscall FUN_00465a37(int *param_1,undefined4 param_2,byte param_3)

{
  int iVar1;
  bool bVar2;
  
  if (((param_3 & 2) == 0) ||
     ((iVar1 = (**(code **)(*param_1 + 8))(param_2), iVar1 == -0x28 &&
      (iVar1 = (**(code **)(*param_1 + 4))(param_2), iVar1 == 0)))) {
    bVar2 = (param_3 & 4) == 0;
    iVar1 = (**(code **)(*param_1 + 0xc))(param_2,bVar2);
    if ((iVar1 != 0) &&
       (((param_3 & 1) != 0 && (iVar1 = (**(code **)(*param_1 + 4))(param_2), iVar1 == 0)))) {
      (**(code **)(*param_1 + 0xc))(param_2,bVar2);
    }
  }
  return;
}

