
void __thiscall FUN_00417771(int *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *local_8;
  
  local_8 = param_1;
  cVar1 = (**(code **)(*param_1 + 0x28))();
  if (cVar1 == '\0') {
    uVar4 = 0xffffffcf;
  }
  else {
    uVar4 = 0;
  }
  FUN_004659fc(uVar4);
  iVar2 = FUN_00401f6f();
  if (iVar2 == 0) {
    iVar2 = FUN_00418360(param_1[6],param_2,&local_8,0);
    *(undefined2 *)(param_3 + 8) = 0;
    **(undefined1 **)(param_3 + 4) = 0;
    if (iVar2 == 0) {
      FUN_004659fc(0xffffff9e);
    }
    else if (*(int *)(iVar2 + 0xc) != -1) {
      for (piVar3 = *(int **)param_1[9]; piVar3 != (int *)((undefined4 *)param_1[9])[1];
          piVar3 = piVar3 + 0x14) {
        if (*piVar3 == *(int *)(iVar2 + 0xc)) goto LAB_004177dd;
      }
      piVar3 = (int *)0x0;
LAB_004177dd:
      if (piVar3 != (int *)0x0) {
        FUN_0046f8e4(piVar3 + 1);
      }
    }
  }
  return;
}

