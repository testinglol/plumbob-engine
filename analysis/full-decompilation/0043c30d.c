
void __thiscall FUN_0043c30d(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  undefined1 local_124 [272];
  undefined **local_14;
  int local_c;
  undefined4 local_8;
  
  FUN_00405584(param_2);
  FUN_0043b76d(local_124);
  iVar2 = FUN_0046f973(local_124);
  if (iVar2 != 0) {
    while (iVar2 = (*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x20) >> 2) + -1, -1 < iVar2) {
      piVar3 = (int *)(*(int *)(param_1 + 0x20) + iVar2 * 4);
      while (((byte)*(undefined4 *)(*piVar3 + 0xb4) & 0xc) != 4) {
        iVar2 = iVar2 + -1;
        piVar3 = piVar3 + -1;
        if (iVar2 < 0) goto LAB_0043c388;
      }
      FUN_0043caba(*(undefined4 *)(*(int *)(param_1 + 0x20) + iVar2 * 4));
    }
LAB_0043c388:
    FUN_0046f8e4(local_124);
    uVar1 = *(undefined1 *)(param_1 + 0x1241);
    *(undefined1 *)(param_1 + 0x1241) = 1;
    iVar2 = (*(code *)**(undefined4 **)(param_1 + 0x360))();
    if (iVar2 != 0) {
      local_8 = 1;
      local_14 = &PTR_FUN_00667020;
      local_c = param_1;
      FUN_00412825((undefined4 *)(param_1 + 0x360));
    }
    *(undefined1 *)(param_1 + 0x1241) = uVar1;
    FUN_0040766a(0xe0,0);
  }
  return;
}

