
bool __thiscall FUN_00582e2a(int *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_2;
  iVar2 = (**(code **)(*param_2 + 0x38))(0x46574156,param_3,&LAB_00582e92);
  if (iVar2 != 0) {
    param_3 = FUN_00420048(iVar2);
    FUN_00420096(iVar2);
    (**(code **)(*piVar1 + 0x50))(iVar2,(int)&param_2 + 2);
    *param_1 = (int)param_2._2_2_;
    FUN_0046f8cb(param_3);
    FUN_00465a06(iVar2);
  }
  return iVar2 != 0;
}

