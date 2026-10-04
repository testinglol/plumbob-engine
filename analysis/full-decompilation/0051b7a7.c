
bool __thiscall FUN_0051b7a7(int *param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = param_2;
  if ((((param_3 < 0x32) || (param_2 < 0)) || (param_1[0x22] - param_1[0x20] <= param_3)) ||
     (param_1[0x21] - param_1[0x1f] <= param_2)) {
    param_2._3_1_ = false;
    cVar2 = FUN_004cff80();
    if (((((cVar2 != '\0') && (0x154 < iVar1)) &&
         ((-1 < param_3 &&
          ((param_3 < 0x32 && (iVar3 = (**(code **)(*param_1 + 0x18))(), iVar3 != 0)))))) &&
        (iVar3 = *(int *)(iVar3 + 0x10c), iVar3 != 0)) &&
       ((*(int **)(iVar3 + 0x60) != (int *)0x0 &&
        (cVar2 = (**(code **)(**(int **)(iVar3 + 0x60) + 0x20))(0x40), cVar2 != '\0')))) {
      iVar4 = (**(code **)(**(int **)(iVar3 + 0x60) + 0xcc))();
      iVar5 = (**(code **)(**(int **)(iVar3 + 0x60) + 0xd0))();
      param_2._3_1_ = 0x80 < *(byte *)(iVar5 * param_3 + iVar4 + -0x155 + iVar1);
      (**(code **)(**(int **)(iVar3 + 0x60) + 0x24))(0x40);
    }
  }
  else {
    param_2._3_1_ = true;
  }
  return param_2._3_1_;
}

