
undefined4 FUN_004dee6e(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x44))(0x424d505f,param_2,*(undefined1 *)(DAT_006e486c + 100),0);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_00420048(iVar1);
    FUN_00420096(iVar1);
    if (param_3 == 3) {
      uVar2 = FUN_004df2ca();
    }
    else {
      uVar2 = FUN_004deed2(uVar2);
    }
    FUN_00465a06(iVar1);
  }
  return uVar2;
}

