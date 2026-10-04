
void __fastcall FUN_005de6fb(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1[0x2d] != 0) {
    if (param_1[0x2d] < 0) {
      (**(code **)(*param_1 + 0x98))();
    }
    if ((char)param_1[0x33] == '\0') {
      (**(code **)(*param_1 + 0x174))(0,0);
    }
    iVar1 = (**(code **)(*param_1 + 0x18))();
    if (iVar1 != 0) {
      iVar1 = param_1[0x2d];
      iVar2 = (**(code **)(*param_1 + 0x18))();
      if (iVar2 != 0) {
        FUN_005da644(iVar2,0x1b,param_1,iVar1,0);
      }
    }
    param_1[0x2d] = 0;
    if ((undefined4 *)param_1[0x34] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0x34])(1);
    }
    param_1[0x34] = 0;
  }
  piVar3 = *(int **)param_1[0xe];
  if (piVar3 != (int *)param_1[0xe]) {
    do {
      (**(code **)(*(int *)piVar3[2] + 0xac))();
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)param_1[0xe]);
  }
  return;
}

