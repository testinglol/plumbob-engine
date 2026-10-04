
void __thiscall FUN_004179f0(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 local_18 [10];
  undefined2 local_e;
  undefined1 local_8 [4];
  
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
    iVar2 = FUN_00418360(param_1[6],param_2,local_8,0);
    if (iVar2 == 0) {
      iVar3 = -99;
    }
    else {
      if (*(int *)(iVar2 + 8) == -1) {
        (**(code **)(*param_1 + 0x7c))(param_2);
      }
      *(undefined4 *)(iVar2 + 0x10) = 0;
      iVar3 = FUN_004181b3(local_18,*(undefined4 *)(iVar2 + 8));
      if (iVar3 == 0) {
        *(undefined2 *)(iVar2 + 6) = local_e;
      }
    }
    FUN_004659fc(iVar3);
  }
  return;
}

