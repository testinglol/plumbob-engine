
int __fastcall FUN_005d2bef(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *local_8;
  
  *(undefined1 *)(param_1 + 7) = 0;
  local_8 = param_1;
  iVar3 = FUN_005d285c();
  if (iVar3 == 0) {
    for (piVar4 = (int *)*param_1; piVar4 != (int *)param_1[1]; piVar4 = piVar4 + 1) {
      iVar3 = FUN_005d2cdc(*piVar4 + 0x14,*piVar4 + 4);
      if (iVar3 != 0) {
        return iVar3;
      }
      puVar1 = *(undefined4 **)(*piVar4 + 4);
      iVar3 = (**(code **)*puVar1)(puVar1,&DAT_00677268,*piVar4 + 8);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = (**(code **)**(undefined4 **)(param_1[3] + 0x38))
                        (*(undefined4 **)(param_1[3] + 0x38),&DAT_00677288,&local_8);
      if (iVar3 < 0) {
        return iVar3;
      }
      piVar2 = *(int **)(*piVar4 + 8);
      iVar3 = (**(code **)(*piVar2 + 0xc))(piVar2,local_8,*piVar4 + 0xc);
      (**(code **)(*local_8 + 8))(local_8);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    iVar3 = 0;
  }
  return iVar3;
}

