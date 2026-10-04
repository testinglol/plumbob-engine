
void FUN_0040e7f7(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_114;
  
  iVar1 = param_2;
  FUN_0040f5c8(param_2);
  iVar2 = FUN_0046fab1(&DAT_006c10a8,0);
  iVar3 = FUN_0046fab1(&DAT_006c10a4,0);
  *(undefined2 *)(iVar1 + 8) = 0;
  **(undefined1 **)(iVar1 + 4) = 0;
  param_2 = CONCAT13(param_2._3_1_,0x43504f);
  if (iVar3 == -1) {
    FUN_0046f8e4(&DAT_006f6c20);
  }
  FUN_0046f847(local_114,iVar2);
  FUN_0046fa24(*(undefined1 *)((int)&param_2 + param_1));
  FUN_0046f847(local_114 + 2 + iVar2,0xffffffff);
  if (iVar3 != -1) {
    iVar2 = FUN_0040cd0e();
    param_2 = CONCAT31(param_2._1_3_,(-(iVar2 != 1) & 7U) + 0x66);
    FUN_0046f8e4(iVar1);
    FUN_0046f8e4(&DAT_006f6c20);
    FUN_0046f847(local_114,iVar3);
    FUN_0046fa24(param_2);
    FUN_0046f847(local_114 + 2 + iVar3,0xffffffff);
  }
  return;
}

