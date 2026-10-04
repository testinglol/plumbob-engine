
int __thiscall FUN_00427281(int param_1,short *param_2)

{
  undefined4 *puVar1;
  short *psVar2;
  char cVar3;
  undefined4 *puVar4;
  int local_8;
  
  puVar4 = *(undefined4 **)(param_1 + 0x148);
  puVar1 = *(undefined4 **)(param_1 + 0x14c);
  local_8 = 0;
  for (; puVar4 != puVar1; puVar4 = puVar4 + 1) {
    psVar2 = (short *)*puVar4;
    if ((((psVar2 != (short *)0x0) && (psVar2 != param_2)) &&
        (cVar3 = FUN_00423f63(), cVar3 != '\0')) &&
       (((psVar2[0x77] != 0 && (param_2[0x77] != psVar2[0x77])) &&
        (cVar3 = FUN_0042720f(psVar2 + 6,(int)*psVar2,param_2 + 6,(int)*param_2), cVar3 != '\0'))))
    {
      local_8 = local_8 + psVar2[0x8b];
    }
  }
  return local_8;
}

