
int __fastcall FUN_005d2c81(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *local_8;
  
  local_8 = (int *)0x0;
  iVar2 = (**(code **)**(undefined4 **)(param_1[3] + 0x38))
                    (*(undefined4 **)(param_1[3] + 0x38),&DAT_00677288,&local_8);
  if ((-1 < iVar2) && (local_8 != (int *)0x0)) {
    for (piVar3 = (int *)*param_1; piVar3 != (int *)param_1[1]; piVar3 = piVar3 + 1) {
      piVar1 = *(int **)(*piVar3 + 8);
      (**(code **)(*piVar1 + 0xc))(piVar1,local_8,*piVar3 + 0xc);
    }
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 8))(local_8);
    }
    iVar2 = 0;
  }
  return iVar2;
}

