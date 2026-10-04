
void __fastcall FUN_005effb4(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  undefined4 local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  if (*(char *)(param_1 + 0x74) == '\0') {
    return;
  }
  piVar1 = *(int **)(param_1 + 0x70);
  if (piVar1 == (int *)0x0) {
    return;
  }
  local_10 = (int *)(**(code **)(*piVar1 + 0x1c))(piVar1,3,0xffffffff);
  if (local_10 == (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(param_1 + 0x70) + 0x20))
                      (*(int **)(param_1 + 0x70),&local_8,local_34);
    if (iVar2 != 0) goto LAB_005f00af;
    GetClientRect(DAT_006fe8cc,(LPRECT)local_24);
    ClientToScreen(DAT_006fe8cc,(LPPOINT)local_24);
    ClientToScreen(DAT_006fe8cc,(LPPOINT)(local_24 + 8));
    (**(code **)*local_8)(local_8,&DAT_006772f8,&local_14);
    (**(code **)(**(int **)(param_1 + 0x78) + 0x14))
              (*(int **)(param_1 + 0x78),local_24,local_14,local_34,0x1000000,0);
    (**(code **)(*local_8 + 8))(local_8);
  }
  if (local_10 == (int *)0x40003) {
    (**(code **)(**(int **)(param_1 + 0x70) + 0xc))(*(int **)(param_1 + 0x70),&local_c);
    (**(code **)(*local_c + 0xc))(local_c,&local_10);
    (**(code **)(*local_10 + 0x1c))(local_10,0);
    *(undefined1 *)(param_1 + 0x74) = 0;
    (**(code **)(*local_c + 8))(local_c);
    (**(code **)(*local_10 + 8))(local_10);
    *(undefined4 *)(param_1 + 0x70) = 0;
    FUN_005f0352(0);
  }
LAB_005f00af:
  piVar1 = *(int **)(param_1 + 0x70);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x18))(piVar1,3,0,0,0);
  }
  return;
}

