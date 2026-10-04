
undefined4 __thiscall FUN_00476d78(int *param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  tagRECT local_20;
  undefined1 local_10 [8];
  undefined4 local_8;
  
  if (DAT_006e54ac == (int *)0x0) {
    uVar4 = 0;
  }
  else {
    local_8 = *(undefined4 *)(param_2 + 0xc);
    iVar2 = (**(code **)(*param_1 + 0xc))();
    local_20.left = *(int *)(iVar2 + 0x68);
    local_20.top = *(int *)(iVar2 + 0x6c);
    local_20.right = *(int *)(iVar2 + 0x70);
    local_20.bottom = *(int *)(iVar2 + 0x74);
    OffsetRect(&local_20,-local_20.left,-local_20.top);
    if ((((local_20.left <= local_8._2_2_) && (local_8._2_2_ < local_20.right)) &&
        (local_20.top <= (short)local_8)) && ((short)local_8 < local_20.bottom)) {
      uVar4 = 0;
      iVar2 = (**(code **)(*param_1 + 0x38))();
      (**(code **)(*DAT_006e54ac + 0x44))(&local_8);
      if (iVar2 == 0) {
        iVar2 = 1;
      }
      sVar1 = (**(code **)(*DAT_006e54ac + 0x10))();
      if (sVar1 != 0) {
        uVar4 = (**(code **)(*param_1 + 0x28))(local_8,iVar2,1);
      }
      puVar3 = (undefined4 *)(**(code **)(*param_1 + 4))(local_10,local_8,1);
      if (param_3 == 1) {
        (**(code **)(*DAT_006e54ac + 0x20))();
      }
      else {
        (**(code **)(*DAT_006e54ac + 0x24))(*puVar3,puVar3[1],uVar4,param_2);
      }
      FUN_00476c67(param_2,1);
    }
    uVar4 = 1;
  }
  return uVar4;
}

