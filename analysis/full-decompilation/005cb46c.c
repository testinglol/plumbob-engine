
undefined4 FUN_005cb46c(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar2 = param_2;
  if (param_2 == (undefined4 *)0x0) {
    (**(code **)(*param_1 + 4))(0);
    uVar4 = 0;
  }
  else {
    puVar1 = (undefined4 *)*param_2;
    param_2 = (int *)0x0;
    iVar3 = (*(code *)*puVar1)(puVar2,&DAT_00677308,&param_2);
    if (iVar3 == 0) {
      (**(code **)(*param_1 + 4))(param_2);
      uVar4 = 0;
      (**(code **)(*param_2 + 8))(param_2);
    }
    else {
      uVar4 = 0xffffffff;
      (**(code **)(*param_1 + 4))(0);
    }
  }
  return uVar4;
}

