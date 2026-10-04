
undefined4 __thiscall FUN_0045c92e(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((*(int *)(param_2 + 0x68) != 0) ||
     (cVar1 = FUN_00463a0f(param_1[0x37],param_1,*(undefined4 *)(param_2 + 0x48)), cVar1 != '\0')) {
    iVar2 = FUN_00463dd9(param_1[0x37],param_1,*(undefined4 *)(param_2 + 0x48));
    if (iVar2 != 0) {
      FUN_00457da4();
      uVar3 = FUN_004561a0(0xf);
      if (((short)uVar3 != 0) &&
         (cVar1 = (**(code **)(*param_1 + 0x34))(iVar2,0,uVar3,0), cVar1 != '\0')) {
        FUN_00463f99(param_1[0x37],param_1,iVar2);
        *(int *)(param_2 + 0x68) = iVar2;
        return 1;
      }
    }
  }
  return 0;
}

