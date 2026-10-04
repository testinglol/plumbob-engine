
void __thiscall FUN_0050a8c0(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)0x0;
  *(int *)(param_1 + 0xd8) = param_2;
  if (param_2 == 0) {
    piVar1 = *(int **)(param_1 + 0xe4);
    FUN_0050a876(piVar1,1);
LAB_0050a8e3:
    FUN_0050a876(*(undefined4 *)(param_1 + 0xe0),0);
    if (param_2 != 2) goto LAB_0050a92b;
    piVar1 = *(int **)(param_1 + 0xe8);
    FUN_0050a876(piVar1,1);
LAB_0050a96e:
    FUN_0050a876(*(undefined4 *)(param_1 + 0xec),0);
    if (param_2 != 4) goto LAB_0050a94f;
    piVar1 = *(int **)(param_1 + 0xf0);
    FUN_0050a876(piVar1,1);
  }
  else {
    FUN_0050a876(*(undefined4 *)(param_1 + 0xe4),0);
    if (param_2 != 1) goto LAB_0050a8e3;
    piVar1 = *(int **)(param_1 + 0xe0);
    FUN_0050a876(piVar1,1);
LAB_0050a92b:
    FUN_0050a876(*(undefined4 *)(param_1 + 0xe8),0);
    if (param_2 != 3) goto LAB_0050a96e;
    piVar1 = *(int **)(param_1 + 0xec);
    FUN_0050a876(piVar1,1);
LAB_0050a94f:
    FUN_0050a876(*(undefined4 *)(param_1 + 0xf0),0);
    if (param_2 == 5) {
      piVar1 = *(int **)(param_1 + 0xf4);
      uVar3 = 1;
      piVar2 = piVar1;
      goto LAB_0050a99a;
    }
  }
  uVar3 = 0;
  piVar2 = *(int **)(param_1 + 0xf4);
LAB_0050a99a:
  FUN_0050a876(piVar2,uVar3);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x168))();
  }
  return;
}

