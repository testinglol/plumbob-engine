
undefined4 __thiscall FUN_004f6c41(int param_1,int *param_2,char param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int *piVar2;
  bool bVar3;
  char cVar4;
  
  FUN_004f778b();
  if ((*(int **)(param_1 + 0x84) == (int *)0x0) ||
     (cVar4 = (**(code **)(**(int **)(param_1 + 0x84) + 0x8c))(1), cVar4 == '\0')) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
    FUN_005ddfdc(1);
  }
  piVar2 = *(int **)(param_1 + 0x84);
  if (param_3 == '\0') {
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x20))(param_2);
      (**(code **)(*param_2 + 0x138))();
    }
  }
  else {
    uVar1 = *(undefined1 *)((int)piVar2 + 0x119);
    FUN_004d3f37(1);
    param_4 = FUN_005daa44(0,param_2);
    FUN_004d3f37(uVar1);
  }
  if ((bVar3) && (param_3 != '\0')) {
    FUN_005ddfdc(0);
  }
  return param_4;
}

