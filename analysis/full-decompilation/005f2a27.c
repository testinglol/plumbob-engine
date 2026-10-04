
void __thiscall
FUN_005f2a27(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x80);
  iVar1 = *(int *)(param_1 + 0x7c);
  iVar2 = *(int *)(param_1 + 0x84);
  iVar3 = *(int *)(param_1 + 0x88);
  FUN_005dda18(param_2,param_3,param_4,param_5);
  if ((((iVar1 != *(int *)(param_1 + 0x7c)) || (iVar2 != *(int *)(param_1 + 0x84))) ||
      (iVar4 != *(int *)(param_1 + 0x80))) || (iVar3 != *(int *)(param_1 + 0x88))) {
    if (*(undefined4 **)(param_1 + 0x198) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_1 + 0x198))(1);
    }
    *(undefined4 *)(param_1 + 0x198) = 0;
  }
  if (((*(int *)(param_1 + 0x88) == *(int *)(param_1 + 0x80)) || (*(int *)(param_1 + 0x130) < 1)) ||
     (*(int **)(param_1 + 0x114) == (int *)0x0)) {
    *(undefined4 *)(param_1 + 0x104) = 0;
  }
  else {
    iVar4 = (**(code **)(**(int **)(param_1 + 0x114) + 0x58))();
    *(int *)(param_1 + 0x104) =
         ((*(int *)(param_1 + 0x88) - iVar4 * *(int *)(param_1 + 0x130)) - *(int *)(param_1 + 0x80))
         / 2;
  }
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x118) = 5;
  *(int *)(param_1 + 0x120) = *(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c);
  *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80);
  return;
}

