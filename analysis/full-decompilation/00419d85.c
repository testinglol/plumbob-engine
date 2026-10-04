
void __thiscall FUN_00419d85(int *param_1,undefined4 param_2)

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
    piVar3 = (int *)FUN_00418e2d(param_2,&local_8,0);
    if (piVar3 == (int *)0x0) {
      uVar4 = 0xffffff9d;
    }
    else {
      if (*piVar3 == -1) {
        (**(code **)(*param_1 + 0x7c))(param_2);
      }
      piVar3[3] = 0;
      *(undefined2 *)(piVar3 + 2) = *(undefined2 *)((int)piVar3 + 10);
      uVar4 = 0;
    }
    FUN_004659fc(uVar4);
  }
  return;
}

