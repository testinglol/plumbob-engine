
void FUN_004696ba(undefined4 param_1,undefined4 param_2,LPRECT param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00469872(param_1);
  iVar2 = FUN_00469872(param_2);
  if ((iVar1 == 0) || (iVar2 == 0)) {
    SetRect(param_3,0,0,0,0);
  }
  else {
    FUN_00469700(iVar1,iVar2,param_3);
  }
  return;
}

