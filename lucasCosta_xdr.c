/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "lucasCosta.h"

bool_t
xdr_dadosAluno (XDR *xdrs, dadosAluno *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->ra))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->nota))
		 return FALSE;
	return TRUE;
}
